#ifndef MEDIAPLAYER_H
#define MEDIAPLAYER_H

#include <QObject>
#include <QMediaPlayer>
#include <QDebug>

#include "playlist.h"

/**
 * @brief The MediaPlayer class provides audio and video playback capabilities.
 *
 * This class extends QMediaPlayer to offer additional features like play/pause control,
 * time tracking, repeat functionality, and playlist management.
 */
class MediaPlayer : public QMediaPlayer
{
    Q_OBJECT

    Q_PROPERTY(bool isPlaying READ isPlaying WRITE setIsPlaying NOTIFY isPlayingChanged FINAL)
    Q_PROPERTY(float mediatime READ mediatime NOTIFY mediatimeChanged FINAL)
    Q_PROPERTY(bool isRepeat READ isRepeat NOTIFY isRepeatChanged FINAL)

public:
    /**
     * @brief Constructs a MediaPlayer instance.
     * @param parent The parent QObject, if any.
     */
    explicit MediaPlayer(QObject *parent = nullptr);

    /**
     * @brief Checks if the media player is currently playing.
     * @return True if the media player is playing, false otherwise.
     */
    bool isPlaying() const;

    /**
     * @brief Sets the playing status of the media player.
     * @param status True to set the media player to playing, false to pause it.
     */
    void setIsPlaying(bool status);

    /**
     * @brief Checks if the media player is in repeat mode.
     * @return True if the media player is in repeat mode, false otherwise.
     */
    bool isRepeat() const;

    /**
     * @brief Sets the repeat status of the media player.
     * @param status True to enable repeat mode, false to disable it.
     */
    void setisRepeat(bool status);

    /**
     * @brief Gets the current media time position in seconds.
     * @return The current media time position.
     */
    float mediatime() const;

    /**
     * @brief Handles end-of-media playback logic.
     */
    void End_of_Media_Logic();

    /**
     * @brief Clears the playlist.
     */
    void ClearPlaylist();

public slots:
    /**
     * @brief Toggles play and pause based on the current playback state.
     */
    void playPause();

    /**
     * @brief Sets the media time position.
     * @param volume The desired media time position in seconds.
     */
    void setMediatime(float volume);

    /**
     * @brief Seeks the media position by a specified time interval in milliseconds.
     * @param delay The time interval to seek in milliseconds.
     */
    void mediaSeek(int delay);

    /**
     * @brief Toggles the repeat status of the media player.
     */
    void changeRepeatStatus();

    /**
     * @brief Sets the playlist for the media player.
     * @param playlist A pointer to the PlayList to be used as the playlist.
     */
    void setPlaylist(PlayList* playlist);

    /**
     * @brief Handles media status changes.
     * @param status The new media status.
     */
    void handleMediaStatus(QMediaPlayer::MediaStatus status);

    /**
     * @brief Gets the current media time in milliseconds.
     * @return The current media time position in milliseconds.
     */
    qint64 mediaTime();

signals:
    /**
     * @brief Signal emitted when the playing status changes.
     */
    void isPlayingChanged();

    /**
     * @brief Signal emitted when the media time changes.
     */
    void mediatimeChanged();

    /**
     * @brief Signal emitted when the repeat status changes.
     */
    void isRepeatChanged();

private:
    /**
     * @brief Pointer to the current playlist being used by the media player.
     */
    PlayList* pr_curplaylist;

    /**
     * @brief Counter for the current playlist item.
     */
    int pr_playlistcount = 0;

    /**
     * @brief Flag indicating if the media player is currently playing.
     */
    bool pr_isplaying = false;

    /**
     * @brief Flag indicating if the media player is in repeat mode.
     */
    bool pr_isrepeat = false;
};

#endif // MEDIAPLAYER_H
