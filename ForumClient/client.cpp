#include "client.h"

Client::Client(QString ip, int port)
{
    socket = new QTcpSocket(this);
    socket->connectToHost(ip,port);
    socket->waitForConnected(2000);
    connect(socket,SIGNAL(readyRead()),this,SLOT(onReadyRead()));
}

QTcpSocket *Client::getSocket()
{
    return socket;
}

void Client::onReadyRead()
{
    QByteArray data = socket->readAll();

    qDebug() << "S-a primit raspunsul: "<<data<<"\n";

    //QString dataStr = QString(data);
}
