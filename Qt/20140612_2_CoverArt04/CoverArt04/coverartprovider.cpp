#include "coverartprovider.h"
#include <QDebug>
#include <QEventLoop>
#include <QTimer>
#include <QMutex>
#include <QThread>

#define TIME_OUT 100
#define TRIAL_TIME 50

CoverArtProvider::CoverArtProvider()
    :QQuickImageProvider(QQuickImageProvider::Image,
                         QQuickImageProvider::ForceAsynchronousImageLoading)
{
    m_mediaPlayer = new QMediaPlayer;
}

CoverArtProvider::~CoverArtProvider()
{
    m_mediaPlayer->stop();
    delete m_mediaPlayer;
}

QImage CoverArtProvider::requestImage(const QString &id, QSize *size, const QSize &requestedSize)
{
    QImage im;
    qDebug() << "requestImage is called. this=" << this <<
                "   thread=" << QThread::currentThread() <<
                "   threadID=" << QThread::currentThreadId();

    //set media file
    QString path(id);
    path = path.remove("file:///");
    qDebug() << "path=" << path;
    while(!m_mutex.tryLock(TIME_OUT)){
        qDebug() << "trying to lock mutex for media player.";
    }
    m_mediaPlayer->setMedia(QUrl::fromLocalFile(path.remove("file://")));

    QMediaPlayer::MediaStatus mediaStatus = m_mediaPlayer->mediaStatus();
    qDebug() << "mediaStatus=" << mediaStatus;
    int i = 0;
    while(mediaStatus == QMediaPlayer::LoadingMedia &&
          i++ < TRIAL_TIME){
        qDebug() << "wait until mediaStatus is changed";
        QThread::msleep(TIME_OUT);
        mediaStatus = m_mediaPlayer->mediaStatus();
    }
    qDebug() << "mediaStatus=" << mediaStatus;

    //if isMetaDataAvailable property is false, wait until it turns to true.
    bool bMetaDataAvailable = m_mediaPlayer->isMetaDataAvailable();
    i = 0;
    if(mediaStatus == QMediaPlayer::LoadedMedia){
        while(!bMetaDataAvailable && i++ < TRIAL_TIME){
            qDebug() << "isMataDataAvailable is false. wait until it turns to true.";
            QThread::msleep(TIME_OUT);
            bMetaDataAvailable = m_mediaPlayer->isMetaDataAvailable();
        }
    }

    if(bMetaDataAvailable){
        //output available metadata to debug window
        QStringList availableData = m_mediaPlayer->availableMetaData();
        qDebug() << "availableDatas are as follows.";
        for (int i = 0; i < availableData.size(); ++i)
            qDebug() << i << availableData.at(i).toLocal8Bit().constData();

        //get cover art from media file and return it
        QStringList embeddedImageKeys;
        embeddedImageKeys << "ThumbnailImage"
                          << "CoverArtImage"
                          << "PosterImage";
        for(int i = 0; i < embeddedImageKeys.size(); ++i){
            im = m_mediaPlayer->metaData("ThumbnailImage").value<QImage>();
            if(!im.isNull())
                break;
        }
        m_mutex.unlock();
        if(!im.isNull()){
            if(requestedSize.width() > 0 && requestedSize.height() > 0){
                im = im.scaled(requestedSize);
            }
            size->setHeight(im.size().height());
            size->setWidth(im.size().width());
        }
        else{
            qDebug() << "embedded image isn't available.";
        }
    }
    else{
        qDebug() << "meta data isn't available.";
        m_mutex.unlock();
    }
    return im;
}
