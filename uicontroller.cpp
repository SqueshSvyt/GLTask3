#include "uicontroller.h"

UIController::UIController(QObject *parent)
    : QObject{parent}
{
    pr_mediaplayer = new QMediaPlayer();
    pr_audiooutput = new QAudioOutput();
    pr_mediaplayer->setAudioOutput(pr_audiooutput);
    pr_audiooutput->setVolume(0.5);
    pr_mediaplayer->setPosition(0);
}

bool UIController::isPlaying() const{
    return pr_isplaying;
}

float UIController::volume() const{
    return pr_audiooutput->volume();
}

void UIController::setVolume(float volume){
    pr_audiooutput->setVolume(volume);
    emit volumeChanged();
}

float UIController::mediatime() const{
    return pr_mediaplayer->position();
}

void UIController::setMediatime(float volume){
    pr_mediaplayer->setPosition(volume);

    emit mediatimeChanged();
}

int UIController::getMaxTime(){
    return pr_mediaplayer->duration();
}

void UIController::setIsPlaying(bool status) {
    if (pr_isplaying != status) {
        pr_isplaying = status;

    }
    emit isPlayingChanged();
}

void UIController::playPause(){
    pr_isplaying = !pr_isplaying;

    if(pr_mediaplayer->isPlaying())
        pr_mediaplayer->pause();
    else
        pr_mediaplayer->play();

    emit isPlayingChanged();
}

void UIController::openFile(QUrl pathtofile){

    if(!pathtofile.isEmpty()){
        if(pr_mediaplayer->isPlaying()){
            pr_mediaplayer->stop();
        }
        pr_mediaplayer->setSource(pathtofile);
    }
    setIsPlaying(false);
    emit OpenFileChanged();
}

QMediaPlayer* UIController::GetPointertoMediaPlayer() const{
    return pr_mediaplayer;
}


