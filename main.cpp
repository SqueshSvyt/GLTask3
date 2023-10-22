#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QQmlContext>
#include <QQuickItem>
#include <QIcon>

//Controllers of Program
#include <Sources/mediaplayer.h>
#include <Sources/filedriver.h>
#include <Sources/audiooutput.h>
#include <Sources/playlist.h>
#include <Sources/library.h>


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    app.setWindowIcon(QIcon(":/MediaPlayer/resources/images/icon.ico"));

    //Create Objects
    MediaPlayer* mediaplayer = new MediaPlayer(&app);
    FileDriver* filedriver = new FileDriver(&app);
    AudioOutput* audiooutput = new AudioOutput(&app);

    //RegisterSingleton
    qmlRegisterSingletonInstance("Logic.Audio",
                                 1, 0, "Audio", audiooutput);

    qmlRegisterSingletonInstance("Logic.Mediaplayer",
                                 1, 0, "Player", mediaplayer);

    qmlRegisterSingletonInstance("Logic.FileDriver",
                                 1, 0, "File", filedriver);

    //Type Register
    qmlRegisterType<MediaLibrary>("MediaLibrary", 1, 0, "MediaLibrary");
    qmlRegisterType<PlayList>("PlayList", 1, 0, "PlayList");

    QQmlApplicationEngine engine;

    const QUrl url(u"qrc:/MediaPlayer/Qml/main.qml"_qs);

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);
    engine.load(url);

    //Add dependencies
    QObject *Object = engine.rootObjects().constFirst();
    QQuickItem *videoOutputItem = Object->findChild<QQuickItem*>("VideoOutput");
    mediaplayer->setVideoOutput(videoOutputItem);
    mediaplayer->setAudioOutput(audiooutput);
    filedriver->setMediaPlayer(mediaplayer);

    return app.exec();
}
