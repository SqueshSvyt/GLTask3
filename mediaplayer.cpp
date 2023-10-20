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

void MediaPlayer::onMediaEnd(QMediaPlayer::MediaStatus status)
{
    if (status == QMediaPlayer::EndOfMedia)
    {
        // Emit a custom signal or perform any necessary actions
        emit mediaStopped();
    }

    emit this->mediaStatusChanged(EndOfMedia);
}

void MediaPlayer::mediaSeek(int delay){
    this->setPosition(this->position() + delay);
}

bool MediaPlayer::isRepeat() const{
    return pr_isrepeat;
}

void MediaPlayer::setisRepeat(bool status){
    pr_isrepeat = status;
}

void MediaPlayer::changeRepeatStatus(){
    pr_isrepeat = !pr_isrepeat;

    emit isRepeatChanged();
}

void MediaPlayer::repeate(QMediaPlayer::MediaStatus status) const{

}

qint64 MediaPlayer::mediaTime(){
    return this->duration();
}
