#include "mainwindow.h"
#include <QApplication>
#include <QObject>
#include <QtCore>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

//QString translate(QString keyword, QString from, QString to);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    //qDebug() << translate("potato", "EN","RO" ) << endl;
    return a.exec();
}

//QString translate(QString keyword, QString from, QString to){
//    //Translate URL
//    QString url = QString("http://translate.google.com/translate_a/t?client=t&text=%0&hl=%1&sl=%2&tl=%1&multires=1&prev=enter&oc=2&ssel=0&tsel=0&uptl=%1&sc=1").arg(keyword).arg(to).arg(from);
//    QNetworkAccessManager manager;
//    QNetworkRequest request(url);
//    QNetworkReply *reply = manager.get(request);

//    //Get reply from Google
//    do {
//        QCoreApplication::processEvents(QEventLoop::ExcludeUserInputEvents);
//    } while(!reply->isFinished());

//    //Convert to string
//    QString translation(reply->readAll());
//    reply->close();
//    //Free memory
//    delete reply;

//    //Remove [[[" from the beginning
//    translation = translation.replace("[[[\"", "");

//    //Extract final translated string
//    translation = translation.mid(0, translation.indexOf(",\"") - 1);

//    return translation;
//}
