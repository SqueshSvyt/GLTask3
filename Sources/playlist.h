#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <QObject>
#include <vector>
#include <QUrl>

/**
 * @brief The PlayList class manages a list of media items.
 *
 * This class allows you to create, modify, and retrieve media items in a playlist.
 */
class PlayList : public QObject
{
    Q_OBJECT

public:
    /**
     * @brief Constructs a PlayList instance.
     * @param parent The parent QObject, if any.
     */
    explicit PlayList(QObject *parent = nullptr);

    /**
     * @brief Retrieves the media item URL at a specified index.
     * @param index The index of the media item in the playlist.
     * @return The URL of the media item as a QUrl.
     */
    QUrl getByUrl(int index);

    /**
     * @brief Gets the size of the playlist.
     * @return The number of media items in the playlist.
     */
    int getSize() const;

public slots:
    /**
     * @brief Retrieves a list of media item URLs in the playlist.
     * @return A vector of QUrl objects representing the media items in the playlist.
     */
    std::vector<QUrl> getPlayListUrl();

    /**
     * @brief Adds a new media item to the playlist.
     * @param indeofmedia The URL of the media item to be added.
     */
    void add(QUrl indeofmedia);

    /**
     * @brief Removes a media item from the playlist at a specified index.
     * @param indexofmedia The index of the media item to be removed.
     */
    void remove(int indexofmedia);

private:
    /**
     * @brief Container for storing media item URLs in the playlist.
     */
    std::vector<QUrl> playlistmedia;
};

#endif // PLAYLIST_H

