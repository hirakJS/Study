#ifndef COVERARTPROVIDER_H
#define COVERARTPROVIDER_H

#include <QQuickImageProvider>
#include <QImage>
#include <QMediaPlayer>
#include <QMutex>

class CoverArtProvider : public QQuickImageProvider
{
public:
    CoverArtProvider();
    ~CoverArtProvider();
    QImage requestImage(const QString &id, QSize *size, const QSize &requestedSize);
private:
    QMediaPlayer *m_mediaPlayer;
    QMutex        m_mutex;
};

#endif // COVERARTPROVIDER_H
