#ifndef LIBRARY_H
#define LIBRARY_H

#include <QObject>
#include <QMediaMetaData>
#include <QMediaPlayer>
#include <QQuickImageProvider>
#include <QImage>
#include <QUrl>
#include <QDir>

#include <vector>
#include "playlist.h"

/**
 * @brief The MediaLibrary class manages a collection of media items and their metadata.
 *
 * This class provides functionality to organize and interact with a library of media items.
 */
class MediaLibrary : public QObject
{
    Q_OBJECT

public:
    /**
     * @brief Constructs a MediaLibrary instance.
     * @param parent The parent QObject, if any.
     */
    explicit MediaLibrary(QObject *parent = nullptr);

    /**
     * @brief Notifies the library of a source change or update.
     */
    void SourceChange() const;

    /**
     * @brief Retrieves a list of media items in the library.
     * @return A vector of QUrl objects representing the media items.
     */
    Q_INVOKABLE std::vector<QUrl> getMediaItems() const;

    /**
     * @brief Retrieves the title of a media item.
     * @param url The URL or path of the media item.
     * @return The title of the media item as a QString.
     */
    Q_INVOKABLE QString getTitle(QUrl url) const;

    /**
     * @brief Retrieves the genre of a media item.
     * @param url The URL or path of the media item.
     * @return The genre of the media item as a QString.
     */
    Q_INVOKABLE QString getGenre(QUrl url) const;

    /**
     * @brief Retrieves the release date of a media item.
     * @param url The URL or path of the media item.
     * @return The release date of the media item as a QString.
     */
    Q_INVOKABLE QString getReleaseDate(QUrl url) const;

    /**
     * @brief Adds a media item to the library.
     * @param url The URL or path of the media item to be added.
     */
    Q_INVOKABLE void addMedia(QUrl url);

private:
    /**
     * @brief Container for storing media items.
     */
    std::vector<QUrl> mediaItems;

    /**
     * @brief Container for storing information about playlists.
     */
    std::vector<PlayList> playlistsinfo;

    /**
     * @brief Media player used for reading metadata of media items.
     */
    QMediaPlayer* mediaplayermeta = new QMediaPlayer();
};

#endif // LIBRARY_H
