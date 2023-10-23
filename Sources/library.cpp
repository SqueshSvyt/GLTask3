#include "library.h"
#include "qurl.h"

MediaLibrary::MediaLibrary(QObject *parent) : QObject(parent)
{

}

std::vector<QUrl> MediaLibrary::getMediaItems() const{
    return mediaItems;
}

QString MediaLibrary::getTitle(QUrl url) const{
    mediaplayermeta->setSource(url);
    QMediaMetaData data = mediaplayermeta->metaData();

    if(data[QMediaMetaData::Title].isNull())
        return "Title: Not Found!";

    return "Title: " + data[QMediaMetaData::Title].toString();
}

QString MediaLibrary::getGenre(QUrl url) const{
    mediaplayermeta->setSource(url);

    QMediaMetaData data = mediaplayermeta->metaData();

    if(data[QMediaMetaData::Genre].isNull())
        return "Genre: Not Found!";

    return "Genre: " + data[QMediaMetaData::Genre].toString();
}

QString MediaLibrary::getReleaseDate(QUrl url) const{
    mediaplayermeta->setSource(url);


    QMediaMetaData data = mediaplayermeta->metaData();

    if(data[QMediaMetaData::Date].isNull())
        return "Date: Not Found!";

    return "Date: " + data[QMediaMetaData::Date].toString();
}

void MediaLibrary::addMedia(QUrl url){
    if(url.isValid())
        mediaItems.push_back(url);
}


