#ifndef MEDIAPLAYER_H
#define MEDIAPLAYER_H

#include <QObject>
#include <QMediaPlayer>

class MediaPlayer : public QMediaPlayer
{
    Q_OBJECT

    Q_PROPERTY(bool isPlaying READ isPlaying WRITE setIsPlaying NOTIFY isPlayingChanged FINAL)
    Q_PROPERTY(float mediatime READ mediatime NOTIFY mediatimeChanged FINAL)

public:
    explicit MediaPlayer(QObject *parent = nullptr);

    bool isPlaying() const;
    void setIsPlaying(bool status);

    float mediatime() const;

public slots:
    void playPause();
    void setMediatime(float volume);
    qint64 mediaTime();

signals:
    void isPlayingChanged();
    void mediatimeChanged();

private:
    bool pr_isplaying = false;
};

#endif // MEDIAPLAYER_H
