#include "library.h"
#include "qurl.h"
#include <string>

MediaLibrary::MediaLibrary(QObject *parent) : QObject(parent)
{
    // Initialize mediaItems with some data (e.g., file paths).

    mediaItems.push_back(QUrl::fromLocalFile("C:/Users/Svyatoslav/Music/Lo-Fi_Chill _4 Minute.mp4"));
    mediaItems.push_back(QUrl::fromLocalFile("C:/Users/Svyatoslav/Music/CelesteSound.mp3.mp3"));
    // Add more media items as needed.
}

std::vector<QString> qMediaMetaDataToVector(const QMediaMetaData &mediaMetaData) {
    std::vector<QString> metaDataVector;
    //1
    metaDataVector.push_back(mediaMetaData.value(QMediaMetaData::Title).toString());
    //2
    metaDataVector.push_back(mediaMetaData.value(QMediaMetaData::Author).toString());
    //3
    metaDataVector.push_back(mediaMetaData.value(QMediaMetaData::Description).toString());
    //4
    metaDataVector.push_back(mediaMetaData.value(QMediaMetaData::Comment).toString());
    //5
    metaDataVector.push_back(mediaMetaData.value(QMediaMetaData::Genre).toString());
    //6
    metaDataVector.push_back(mediaMetaData.value(QMediaMetaData::Language).toString());
    //7
    metaDataVector.push_back(mediaMetaData.value(QMediaMetaData::Publisher).toString());
    //8
    metaDataVector.push_back(mediaMetaData.value(QMediaMetaData::Copyright).toString());
    //9
    metaDataVector.push_back(mediaMetaData.value(QMediaMetaData::LeadPerformer).toString());
    //10
    metaDataVector.push_back(mediaMetaData.value(QMediaMetaData::Composer).toString());
    //11
    metaDataVector.push_back(mediaMetaData.value(QMediaMetaData::AlbumTitle).toString());
    //12
    metaDataVector.push_back(mediaMetaData.value(QMediaMetaData::AlbumArtist).toString());
    //13
    metaDataVector.push_back(mediaMetaData.value(QMediaMetaData::ContributingArtist).toString());
    //14
    metaDataVector.push_back(mediaMetaData.value(QMediaMetaData::Composer).toString());
    //15
    metaDataVector.push_back(mediaMetaData.value(QMediaMetaData::AudioCodec).toString());
    //16
    metaDataVector.push_back(mediaMetaData.value(QMediaMetaData::VideoCodec).toString());
    //17
    metaDataVector.push_back(mediaMetaData.value(QMediaMetaData::Resolution).toString());
    //18
    metaDataVector.push_back(mediaMetaData.value(QMediaMetaData::Url).toString());
    //19
    metaDataVector.push_back(mediaMetaData.value(QMediaMetaData::MediaType).toString());

    return metaDataVector;
}


std::vector<QUrl> MediaLibrary::getMediaItems() const
{
    return mediaItems;
}
