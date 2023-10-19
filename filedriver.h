#ifndef FILEDRIVER_H
#define FILEDRIVER_H

#include <QObject>

#include "mediaplayer.h"

class FileDriver : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool OpenFile NOTIFY OpenFileChanged FINAL)
public:
    explicit FileDriver(QObject *parent = nullptr);

    void setMediaPlayer(MediaPlayer* mediaplayer);

public slots:
    void openFile(QUrl pathtofile);


signals:
    void OpenFileChanged();
private:
    MediaPlayer* pr_mediaplayer;
};

#endif // FILEDRIVER_H
