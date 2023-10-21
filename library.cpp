#include "library.h"
#include "qurl.h"

MediaLibrary::MediaLibrary(QObject *parent) : QObject(parent)
{
    // Initialize mediaItems with some data (e.g., file paths).

    mediaItems.push_back(QUrl::fromLocalFile("C:/Users/olegs/Music/Feint - We Won't Be Alone (feat. Laura Brehm).mp4"));
    mediaItems.push_back(QUrl::fromLocalFile("C:/Users/olegs/Music/cyberpank.mp3"));
    // Add more media items as needed.
}


QString MediaLibrary::getTitle(const QString &filePath) const
{
    mediaplayermeta->setSource(QUrl::fromLocalFile(filePath));

    QMediaMetaData title = mediaplayermeta->metaData();

    return " ";
}

QString MediaLibrary::getArtist(const QUrl &filePath) const
{
    return " ";
}

//QTime MediaLibrary::getDuration(const QUrl &filePath)
//{

//}


std::vector<QUrl> MediaLibrary::getMediaItems() const
{
    return mediaItems;
}
