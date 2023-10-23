#ifndef AUDIOOUTPUT_H
#define AUDIOOUTPUT_H

#include <QObject>
#include <QAudioOutput>

class AudioOutput : public QAudioOutput
{
    Q_OBJECT

    // Properties for controlling volume and mute state
    Q_PROPERTY(float vol READ vol NOTIFY volChanged FINAL)
    Q_PROPERTY(bool isMute READ isMute NOTIFY isMuteChanged FINAL)

public:
    /**
     * @brief AudioOutput constructor.
     * @param parent The parent QObject, if any.
     */
    explicit AudioOutput(QObject *parent = nullptr);

    /**
     * @brief Getter for the current volume level.
     * @return The current volume level as a float.
     */
    float vol() const;

    /**
     * @brief Getter for the mute state.
     * @return True if audio is muted, false otherwise.
     */
    bool isMute() const;

public slots:
    /**
     * @brief Slot to set the volume level.
     * @param volume The desired volume level as a float (0.0 to 1.0).
     */
    void setVol(float volume);

    /**
     * @brief Slot to mute the audio.
     */
    void mute_audio();

signals:
    /**
     * @brief Signal emitted when the volume property changes.
     */
    void volChanged();

    /**
     * @brief Signal emitted when the mute state property changes.
     */
    void isMuteChanged();
};

#endif // AUDIOOUTPUT_H
