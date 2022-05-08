#include <QCoreApplication>
#include "server.h"
#include <QDir>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Server server;
    server.StartServer();


    return a.exec();
}
