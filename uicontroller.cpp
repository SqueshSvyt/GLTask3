#include "uicontroller.h"

UIController::UIController(QObject *parent)
    : QObject{parent}
{
    playercontroller = new MediaPlayerController();
}

bool UIController::isPlaying() const{
    return pr_isplaying;
}

void UIController::playPause(){
    pr_isplaying = !pr_isplaying;
    playercontroller->PlayPause();

    emit isPlayingChanged();
}

void UIController::openFile(QUrl pathtofile){

    if(!pathtofile.isEmpty())
        playercontroller->SetNewUrl(pathtofile);

    emit OpenFileChanged();
}


MediaPlayerController* UIController::Getplayercontroller() const{
    return playercontroller;
}
