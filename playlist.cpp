#include "playlist.h"

PlayList::PlayList(QObject* parent)
    : QObject{parent}
{

}

std::vector<QUrl> PlayList::getPlayListUrl(){
    return playlistmedia;
}

void PlayList::add(QUrl indeofmedia){
    playlistmedia.push_back(indeofmedia);
}

void PlayList::remove(int indexofmedia){
    if(indexofmedia >= 0 && indexofmedia < playlistmedia.size())
        playlistmedia.emplace(playlistmedia.begin() + indexofmedia);

}

int PlayList::getSize() const{
    return playlistmedia.size();
}

QUrl PlayList::getByUrl(int index){
    return playlistmedia[index];
}
