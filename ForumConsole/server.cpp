#include "server.h"

Server::Server(QObject *parent)
    : QTcpServer{parent}
{
    server = new QTcpServer(this);

    connect(server,SIGNAL(newConnection()),this,SLOT(newConnection()));
}

void Server::StartServer()
{
    if(!this->listen(QHostAddress::Any,1234)){
        qDebug() << "Could not start server";
        return;
    }else{
        qDebug() << "Listening...";
    }
}

void Server::incomingConnection(qintptr socketDescriptor)
{
    qDebug() << socketDescriptor <<" Connecting...";
    Thread *thr = new Thread(socketDescriptor,this);
    connect(thr,SIGNAL(finished()),thr,SLOT(deleteLater()));
    thr->start();

}

void Server::newConnection(){
    QTcpSocket *socket = server->nextPendingConnection();
    socket->write("Hello client\r\n");
    socket->flush();
    socket->waitForBytesWritten(3000);
    socket->close();
}
