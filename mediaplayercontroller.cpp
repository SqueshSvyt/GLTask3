#include "mediaplayercontroller.h"

MediaPlayerController::MediaPlayerController()
{
    pr_mediaplayer = new QMediaPlayer();
    pr_audioOutput = new QAudioOutput();
    pr_mediaplayer->setAudioOutput(pr_audioOutput);
}

void MediaPlayerController::SetNewUrl(QUrl url){
    pr_mediaplayer->stop();
    pr_position = 0;
    pr_mediaplayer->setSource(url);
}

void MediaPlayerController::SetVolume(float level){
    pr_audioOutput->setVolume(level);
}

void MediaPlayerController::PlayPause()
{
    if(pr_mediaplayer->isPlaying()){
        pr_position = pr_mediaplayer->position();
        pr_mediaplayer->stop();
        return;
    }

    pr_mediaplayer->setPosition(pr_position);
    pr_mediaplayer->play();
}



QMediaPlayer* MediaPlayerController::GetPlayerPoiter() const{
    return pr_mediaplayer;
}
