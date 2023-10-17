#include <QGuiApplication>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QIcon>

//Controllers of Program
#include <uicontroller.h>


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    //Create Objects
    UIController* uicontroller = new UIController(&app);

    //Create Containres
    qmlRegisterSingletonInstance("com.company.UIController",
                                 1, 0, "UIController", uicontroller);



    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("mediaplayer",
        uicontroller->Getplayercontroller()->GetPlayerPoiter()->source());

    const QUrl url(u"qrc:/MediaPlayer/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
