#ifndef LIBRARY_H
#define LIBRARY_H

#include <QObject>
#include <QUrl>
#include <QMediaMetaData>
#include <QMediaPlayer>
#include <vector>

class MediaLibrary : public QObject
{
    Q_OBJECT

public:
    explicit MediaLibrary(QObject *parent = nullptr);

    Q_INVOKABLE std::vector<QUrl> getMediaItems() const;

    Q_INVOKABLE std::vector<QString> getMetaDatainfo(const QUrl &filePath) const;

private:
    std::vector<QUrl> mediaItems;
    QMediaPlayer* mediaplayermeta = new QMediaPlayer();
};

#endif // LIBRARY_H
