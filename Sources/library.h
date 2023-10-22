#ifndef LIBRARY_H
#define LIBRARY_H

#include <QObject>
#include <QMediaMetaData>
#include <QMediaPlayer>
#include <QQuickImageProvider>
#include <QImage>
#include <QUrl>

#include <vector>
#include "playlist.h"

class MediaLibrary : public QObject
{
    Q_OBJECT

public:
    explicit MediaLibrary(QObject *parent = nullptr);

    void SourceChange() const;

    Q_INVOKABLE std::vector<QUrl> getMediaItems() const;
    Q_INVOKABLE QString getTitle(QUrl url) const;
    Q_INVOKABLE QString getGenre(QUrl url) const;
    Q_INVOKABLE QString getReleaseDate(QUrl url) const;

    Q_INVOKABLE void addMedia(QUrl url);

private:
    std::vector<QUrl> mediaItems;
    std::vector<PlayList> playlistsinfo;
    QMediaPlayer* mediaplayermeta = new QMediaPlayer();
};

#endif // LIBRARY_H
