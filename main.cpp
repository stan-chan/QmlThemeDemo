#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "xml_helper.h"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<XmlHelper>("XmlHelper",1,0,"XmlHelper");
    QQmlApplicationEngine engine;
//    engine.addImportPath("qrc:/");
    const QUrl url(u"qrc:/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    XmlHelper xml;
//    xml.ReadXml();
    return app.exec();
}
