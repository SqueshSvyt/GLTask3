#ifndef FILEDRIVER_H
#define FILEDRIVER_H

#include <QObject>
#include "mediaplayer.h"

/**
 * @brief The FileDriver class handles file-related operations for the MediaPlayer.
 *
 * This class is responsible for opening and interacting with media files through the MediaPlayer.
 */
class FileDriver : public QObject
{
    Q_OBJECT

public:
    /**
     * @brief Constructs a FileDriver instance.
     * @param parent The parent QObject, if any.
     */
    explicit FileDriver(QObject *parent = nullptr);

    /**
     * @brief Sets the MediaPlayer instance to be used for playing media files.
     * @param mediaplayer A pointer to the MediaPlayer instance.
     */
    void setMediaPlayer(MediaPlayer* mediaplayer);

public slots:
    /**
     * @brief Opens a media file in the associated MediaPlayer.
     * @param pathtofile The URL or path to the media file to be opened.
     */
    void openFile(QUrl pathtofile);

private:
    /**
     * @brief Pointer to the MediaPlayer instance for file interaction.
     */
    MediaPlayer* pr_mediaplayer;
};

#endif // FILEDRIVER_H

