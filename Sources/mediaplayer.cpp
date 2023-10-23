#include "mediaplayer.h"

MediaPlayer::MediaPlayer(QObject* parent):
    QMediaPlayer{parent}
{
    this->setPosition(0);

    connect(this, &QMediaPlayer::mediaStatusChanged, this, &MediaPlayer::handleMediaStatus);
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
    if(this->loops() == QMediaPlayer::Infinite)
        this->setLoops(1);
    else
        this->setLoops(QMediaPlayer::Infinite);


    emit isRepeatChanged();
}

void MediaPlayer::setPlaylist(PlayList* playlist){
    pr_curplaylist = playlist;
    pr_playlistcount = 0;
    if(playlist->getSize() > 0){
        this->setSource(pr_curplaylist->getByUrl(pr_playlistcount));
        this->playPause();
    }
}

void MediaPlayer::ClearPlaylist(){
    pr_curplaylist = nullptr;
    pr_playlistcount = 0;
}

void End_Media(MediaPlayer* player){
    player->setPosition(0);
    player->playPause();
}

void MediaPlayer::End_of_Media_Logic(){
    if(pr_curplaylist != nullptr){
        if(pr_playlistcount == pr_curplaylist->getSize() - 1){
            pr_playlistcount = 0;
            this->setSource(pr_curplaylist->getByUrl(pr_playlistcount));

            if(pr_isrepeat){
                return;
            }

            this->play();
            End_Media(this);
            return;
        }
        pr_playlistcount++;
        this->setSource(pr_curplaylist->getByUrl(pr_playlistcount));
        this->play();
        return;
    }
    if(pr_isrepeat == false)
        End_Media(this);
}

void MediaPlayer::handleMediaStatus(QMediaPlayer::MediaStatus status)
{
    if (status == QMediaPlayer::EndOfMedia)
    {
        this->End_of_Media_Logic();
    }
}

qint64 MediaPlayer::mediaTime(){
    return this->duration();
}

std::vector<QString> MediaPlayer::plmetadata(){
    std::vector<QString> vector;

    auto metadata = this->metaData();

    vector.push_back(metadata[QMediaMetaData::Title].toString());
    vector.push_back(metadata[QMediaMetaData::Author].toString());
    vector.push_back(metadata[QMediaMetaData::Genre].toString());
    vector.push_back(metadata[QMediaMetaData::Date].toString());
    vector.push_back(metadata[QMediaMetaData::AlbumTitle].toString());
    vector.push_back(metadata[QMediaMetaData::Language].toString());
    vector.push_back(metadata[QMediaMetaData::Description].toString());
    vector.push_back(metadata[QMediaMetaData::VideoCodec].toString());
    vector.push_back(metadata[QMediaMetaData::AudioCodec].toString());
    vector.push_back(metadata[QMediaMetaData::MediaType].toString());
    vector.push_back(metadata[QMediaMetaData::FileFormat].toString());
    vector.push_back(metadata[QMediaMetaData::Duration].toString());

    return vector;
}
