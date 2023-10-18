#ifndef UICONTROLLER_H
#define UICONTROLLER_H

#include <QMediaPlayer>
#include <QAudioOutput>
#include <QObject>
#include <QUrl>

class UIController : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool OpenFile NOTIFY OpenFileChanged FINAL)
    Q_PROPERTY(bool isPlaying READ isPlaying WRITE setIsPlaying NOTIFY isPlayingChanged FINAL)
    Q_PROPERTY(float int READ volume NOTIFY volumeChanged FINAL)
    Q_PROPERTY(float mediatime READ mediatime NOTIFY mediatimeChanged FINAL)
public:
    explicit UIController(QObject *parent = nullptr);

    bool isPlaying() const;
    void setIsPlaying(bool status);

    float volume() const;

    float mediatime() const;

    QMediaPlayer* GetPointertoMediaPlayer() const;
public slots:
    void playPause();
    void openFile(QUrl pathtofile);
    void setVolume(float volume);
    void setMediatime(float volume);
    int getMaxTime();

signals:
    void isPlayingChanged();
    void OpenFileChanged();
    void volumeChanged();
    void mediatimeChanged();

private:
    bool pr_isplaying = false;
    QMediaPlayer* pr_mediaplayer;
    QAudioOutput* pr_audiooutput;
};


#endif // UICONTROLLER_H
