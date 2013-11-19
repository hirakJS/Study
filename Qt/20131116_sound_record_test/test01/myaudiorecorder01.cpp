#include "myaudiorecorder01.h"
#include <QDebug>
#include <QAudioDeviceInfo>

MyAudioRecorder01::MyAudioRecorder01(QQuickItem *parent) :
    QQuickItem(parent)
{
//    QStringList codecs;
//    codecs = QAudioDeviceInfo::supportedCodecs();
//    qDebug() << "new QAudioRecorder" << codecs;
    m_audioRecorder = new QAudioRecorder(this);
    QAudioEncoderSettings audioSettings;
    audioSettings.setCodec("audio/FLAC");
    audioSettings.setQuality(QMultimedia::HighQuality);

    m_audioRecorder->setEncodingSettings(audioSettings);

    m_audioRecorder->setOutputLocation(QUrl::fromLocalFile("test.flac"));

    QStringList inputs = m_audioRecorder->audioInputs();
    QString selectedInput = m_audioRecorder->defaultAudioInput();

//    foreach (QString input, inputs) {
//        QString description = m_audioRecorder->audioInputDescription(input);
//        // show descriptions to user and allow selection
//        selectedInput = input;
//    }

    m_audioRecorder->setAudioInput(selectedInput);
}

void MyAudioRecorder01::record()
{
    m_audioRecorder->record();
}

void MyAudioRecorder01::stop()
{
    m_audioRecorder->stop();
}
