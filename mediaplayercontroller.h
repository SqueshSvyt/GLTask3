#ifndef MEDIAPLAYERCONTROLLER_H
#define MEDIAPLAYERCONTROLLER_H

#include <QMediaPlayer>
#include <QAudioOutput>

class MediaPlayerController
{
public:
    MediaPlayerController();

    void SetNewUrl(QUrl url);

    void SetVolume(float level);

    void PlayPause();

    void Reset();

    QMediaPlayer* GetPlayerPoiter() const;
private:
    QMediaPlayer* pr_mediaplayer;
    QAudioOutput* pr_audioOutput;
    unsigned long long pr_position;
};

#endif // MEDIAPLAYERCONTROLLER_H
