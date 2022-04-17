#include <QCoreApplication>
#include "server.h"
#include "DataBase.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //Server server;
   // server.StartServer();
    DataBase db;
    db.ConnectDB();
    return a.exec();
}
