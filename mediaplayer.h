#ifndef MEDIAPLAYER_H
#define MEDIAPLAYER_H

#include <QObject>
#include <QMediaPlayer>
#include <QDebug>

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

    void repeate(QMediaPlayer::MediaStatus status) const;

public slots:
    void playPause();
    void setMediatime(float volume);
    void onMediaEnd(QMediaPlayer::MediaStatus status);
    void mediaSeek(int delay);
    void changeRepeatStatus();
    qint64 mediaTime();

signals:
    void isPlayingChanged();
    void mediatimeChanged();
    void mediaStopped();
    void isRepeatChanged();

private:
    bool pr_isplaying = false;
    bool pr_isrepeat = false;
};

#endif // MEDIAPLAYER_H
