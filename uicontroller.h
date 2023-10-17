#ifndef UICONTROLLER_H
#define UICONTROLLER_H

#include <QObject>

#include "mediaplayercontroller.h"
#include "filefinder.h"

class UIController : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool OpenFile NOTIFY OpenFileChanged FINAL)
    Q_PROPERTY(bool isPlaying READ isPlaying NOTIFY isPlayingChanged FINAL)

public:
    explicit UIController(QObject *parent = nullptr);

    bool isPlaying() const;

    MediaPlayerController* Getplayercontroller() const;

public slots:
    void playPause();
    void openFile(QUrl pathtofile);
signals:
    void isPlayingChanged();
    void OpenFileChanged();

private:
    bool pr_isplaying = false;
    MediaPlayerController *playercontroller;
    FileFinder *filefinder;
};


#endif // UICONTROLLER_H
