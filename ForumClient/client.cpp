#include "client.h"

Client::Client(QString ip, int port)
{
    socket = new QTcpSocket(this);
    socket->connectToHost(ip,port);
    socket->waitForConnected();
    connect(socket,SIGNAL(readyRead()),this,SLOT(onReadyRead()));
}

QTcpSocket *Client::getSocket()
{
    return socket;
}

QStringList Client::getLastMsg()
{
    return lastResponseMsg;
}

void Client::setUsername(QString user)
{
    username = user;
}

QString Client::getUsername()
{
    return username;
}

void Client::onReadyRead()
{
    QByteArray Data = socket->readAll();
    qDebug() << "S-a primit raspunsul: "<<Data<<"\n";

    this->lastResponseMsg = QString(Data).split('|');

}
