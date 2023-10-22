#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <QObject>
#include <vector>
#include<QUrl>

class PlayList : public QObject
{
    Q_OBJECT

public:
    explicit PlayList(QObject *parent = nullptr);

    QUrl getByUrl(int index);
    int getSize() const;


public slots:
    std::vector<QUrl> getPlayListUrl();
    void add(QUrl indeofmedia);
    void remove(int indexofmedia);

private:
    std::vector<QUrl> playlistmedia;
};

#endif // PLAYLIST_H
