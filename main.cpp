#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QQmlContext>
#include <QQuickItem>
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

    const QUrl url(u"qrc:/MediaPlayer/main.qml"_qs);

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);
    engine.load(url);

    QObject *Object = engine.rootObjects().constFirst();
    QQuickItem *videoOutputItem = Object->findChild<QQuickItem*>("VideoOutput");
    uicontroller->GetPointertoMediaPlayer()->setVideoOutput(videoOutputItem);

    return app.exec();
}
