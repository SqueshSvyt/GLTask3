#ifndef FILEDRIVER_H
#define FILEDRIVER_H

#include <QObject>

#include "mediaplayer.h"

class FileDriver : public QObject
{
    Q_OBJECT

public:
    explicit FileDriver(QObject *parent = nullptr);

    void setMediaPlayer(MediaPlayer* mediaplayer);

public slots:
    void openFile(QUrl pathtofile);

private:
    MediaPlayer* pr_mediaplayer;
};

#endif // FILEDRIVER_H
