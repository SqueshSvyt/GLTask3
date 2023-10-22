#include "filedriver.h"

FileDriver::FileDriver(QObject *parent)
    : QObject{parent}
{

}

void FileDriver::setMediaPlayer(MediaPlayer* mediaplayer){
    pr_mediaplayer = mediaplayer;
}

void FileDriver::openFile(QUrl pathtofile){

    if(pr_mediaplayer == nullptr)
        return;

    if(!pathtofile.isEmpty()){
        pr_mediaplayer->setSource(pathtofile);
        pr_mediaplayer->pause();
    }

    pr_mediaplayer->ClearPlaylist();
}
