#include "mediaplayer.h"

MediaPlayer::MediaPlayer(QObject* parent):
    QMediaPlayer{parent}
{
    this->setPosition(0);
}

bool MediaPlayer::isPlaying() const{
    return this->pr_isplaying;
}

void MediaPlayer::setIsPlaying(bool status) {
    if (pr_isplaying != status)
        pr_isplaying = status;

    emit isPlayingChanged();
}

float MediaPlayer::mediatime() const{
    return this->position();
}

void MediaPlayer::setMediatime(float volume){
    this->setPosition(volume);

    emit mediatimeChanged();
}

void MediaPlayer::playPause(){
    if(pr_isplaying)
        this->pause();
    else
        this->play();

    pr_isplaying = !pr_isplaying;

    emit isPlayingChanged();
}

qint64 MediaPlayer::mediaTime(){
    return this->duration();
}
