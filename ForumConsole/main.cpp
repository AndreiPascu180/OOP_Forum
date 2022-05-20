#include <QCoreApplication>
#include "server.h"
#include <QDir>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Server::getServer().StartServer();

//    QTextStream out(stdout);

//     QDate cd = QDate::currentDate();
//      QTime ct = QTime::currentTime();


//      QString Data= cd.toString(Qt::ISODate) + " "+ct.toString();
//      qDebug()<<Data;
    return a.exec();
}
