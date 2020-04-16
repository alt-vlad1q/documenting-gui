#include <QtQuick/QQuickView>
#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);


    QQmlApplicationEngine view;
//    view.setResizeMode(QQuickView::SizeRootObjectToView);
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&view, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);
    view.load(url);
    return app.exec();
}
