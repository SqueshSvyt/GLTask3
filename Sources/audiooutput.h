#ifndef AUDIOOUTPUT_H
#define AUDIOOUTPUT_H

#include <QObject>
#include <QAudioOutput>

class AudioOutput : public QAudioOutput
{
    Q_OBJECT

    Q_PROPERTY(float vol READ vol NOTIFY volChanged FINAL)
    Q_PROPERTY(bool isMute READ isMute NOTIFY isMuteChanged FINAL)
public:
    explicit AudioOutput(QObject *parent = nullptr);

    float vol() const;

    bool isMute() const;
public slots:
    void setVol(float volume);
    void mute_audio();

signals:
    void volChanged();
    void isMuteChanged();
};

#endif // AUDIOOUTPUT_H
