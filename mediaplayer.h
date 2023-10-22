#ifndef MEDIAPLAYER_H
#define MEDIAPLAYER_H

#include <QObject>
#include <QMediaPlayer>
#include <QDebug>

#include "playlist.h"

class MediaPlayer : public QMediaPlayer
{
    Q_OBJECT

    Q_PROPERTY(bool isPlaying READ isPlaying WRITE setIsPlaying NOTIFY isPlayingChanged FINAL)
    Q_PROPERTY(float mediatime READ mediatime NOTIFY mediatimeChanged FINAL)
    Q_PROPERTY(bool isRepeat READ isRepeat NOTIFY isRepeatChanged FINAL)
public:
    explicit MediaPlayer(QObject *parent = nullptr);

    bool isPlaying() const;
    void setIsPlaying(bool status);

    bool isRepeat() const;
    void setisRepeat(bool status);

    float mediatime() const;

    void End_of_Media_Logic();

    void ClearPlaylist();
public slots:
    void playPause();
    void setMediatime(float volume);
    void mediaSeek(int delay);
    void changeRepeatStatus();
    void setPlaylist(PlayList* playlist);
    void handleMediaStatus(QMediaPlayer::MediaStatus status);
    qint64 mediaTime();

signals:
    void isPlayingChanged();
    void mediatimeChanged();
    void isRepeatChanged();

private:
    PlayList* pr_curplaylist;
    int pr_playlistcount = 0;
    bool pr_isplaying = false;
    bool pr_isrepeat = false;
};

#endif // MEDIAPLAYER_H
