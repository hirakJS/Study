#ifndef MYAUDIORECORDER01_H
#define MYAUDIORECORDER01_H

#include <QQuickItem>
#include <QAudioRecorder>

class MyAudioRecorder01 : public QQuickItem
{
    Q_OBJECT
public:
    explicit MyAudioRecorder01(QQuickItem *parent = 0);

signals:

public slots:

    void record();
    void stop();

private:
    QAudioRecorder* m_audioRecorder;
};

#endif // MYAUDIORECORDER01_H
