#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QQmlContext>
#include <QQuickItem>
#include <QIcon>

//Controllers of Program
#include <mediaplayer.h>
#include <filedriver.h>
#include <audiooutput.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    //Create Objects
    MediaPlayer* mediaplayer = new MediaPlayer(&app);
    FileDriver* filedriver = new FileDriver(&app);
    AudioOutput* audiooutput = new AudioOutput(&app);

    //Create Containres
    qmlRegisterSingletonInstance("Logic.Audio",
                                 1, 0, "Audio", audiooutput);

    qmlRegisterSingletonInstance("Logic.Mediaplayer",
                                 1, 0, "Player", mediaplayer);

    qmlRegisterSingletonInstance("Logic.FileDriver",
                                 1, 0, "File", filedriver);

    QQmlApplicationEngine engine;

    const QUrl url(u"qrc:/MediaPlayer/main.qml"_qs);

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
