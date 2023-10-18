#include "videooutput.h"

VideoOutput::VideoOutput(QObject *parent) :
    m_output(nullptr),
    m_player(nullptr),
    surface(nullptr),
    m_status(tr("No media")),
    probe(nullptr)
{
    setParent(parent);
}

/*
 * Save the `VideoOutput` object from qml.
 */
void VideoOutput::setTargetOutput(QQuickItem *output) noexcept
{
    m_output = output;
    emit targetOutputChanged();
}

/*
 * Save the `MediaObject` object from qml.
 */
void VideoOutput::setMediaPlayer(MediaPlayer *player)
{
    m_player = player;
    m_player->setParent(this);
    // Cast `QObject *` to `QMediaPlayer *`.
    QMediaPlayer *p_player = qobject_cast<QMediaPlayer *>(m_player->player());
    connect(p_player, &QMediaPlayer::stateChanged, this, &VideoOutput::updateState);
    connect(p_player, &QMediaPlayer::mediaStatusChanged, this, &VideoOutput::updateStatus);
    // Object for update the current video frame.
    probe = new QVideoProbe();
    probe->setSource(p_player);
    connect(probe, &QVideoProbe::videoFrameProbed, this, [this](const QVideoFrame &frame){
        current_frame = frame;
    });
    emit mediaPlayerChanged();
    emit invalidMedia();
}

/*
 * Changes the state of the media.
 */
void VideoOutput::updateState(const QMediaPlayer::State& state) noexcept
{
    switch (state) {
    case QMediaPlayer::PlayingState:
        m_status = tr("Playing");
        break;
    case QMediaPlayer::PausedState:
        m_status = tr("Paused");
        break;
    case QMediaPlayer::StoppedState:
        m_status = tr("Stopped");
        break;
    }
    emit statusChanged();
}

/*
 * Changes the status of the media.
 */
void VideoOutput::updateStatus(const QMediaPlayer::MediaStatus& status) noexcept
{
    switch (status) {
    case QMediaPlayer::NoMedia:
        m_status = tr("No media");
        emit invalidMedia();
        break;
    case QMediaPlayer::LoadingMedia:
        m_status = tr("Loading media");
        break;
    case QMediaPlayer::LoadedMedia:
        m_status = tr("Media loaded");
        emit loadedMedia();
        break;
    case QMediaPlayer::BufferingMedia:
        m_status = tr("Buffering");
        break;
    case QMediaPlayer::InvalidMedia:
        m_status = tr("Invalid media");
        emit invalidMedia();
        break;
    default:
        break;
    }
    emit statusChanged();
}

/*
 * Make a screenshot from the video frame.
 */
void VideoOutput::snapshot()
{
    QImage image;
    QVideoFrame frame(current_frame);
    // Map the content of a video frame to system memory.
    if (!frame.map(QAbstractVideoBuffer::ReadOnly)) {
        emit snapshotError(tr("Impossible load the content of video frame into the system memory."));
        return ;
    }
    // Convert the video frame to the image.
    image = convertYUV420pToRGB32(frame.bits(), frame.width(), frame.height());
    // Release memory.
    frame.unmap();
    if (image.isNull()) {
        emit snapshotError(tr("The image is empty."));
        return ;
    }
    QPixmap screenshot = QPixmap::fromImage(image);
    // Creates a directory for saving screenshots.
    // For example: `/home/$(user)/Pictures/player_screenshots/` .
    QDir directory(QStandardPaths::writableLocation(QStandardPaths::PicturesLocation) +
                   QDir::separator() + "player_screenshots");
    if (!directory.exists()) {
        QDir().mkpath(directory.path());
    }
    // Gets the unique name of the file.
    QString filename = getUniqueName(directory.path());
    QFile file(filename + ".png");
    if (!file.open(QIODevice::WriteOnly)) {
        emit snapshotError(tr("Can not create image. Maybe you don`t have enough rights."));
        return ;
    }
    if (!screenshot.save(&file, "png", 100)) {
        emit snapshotError(tr("The image can not be saved."));
        return ;
    }
}
