#include "thread.h"

//Thread::Thread(qintptr ID, QObject *parent) : QThread(parent)
//{
//    this->socketDescriptor = ID;
//}

void Thread::run(){
    //thread starts here
    qDebug() << "Starting thread";
    socket = new QTcpSocket();
    if(!socket->setSocketDescriptor(this->socketDescriptor)){
        qDebug() << "There was a problem connecting";
        return;
    }

    connect(socket,SIGNAL(readyRead()),this,SLOT(readyRead()),Qt::DirectConnection);
    connect(socket,SIGNAL(disconnected()),this,SLOT(disconnected()),Qt::DirectConnection);

    qDebug() << socketDescriptor << " Client connected";

    exec();
}

void Thread::readyRead(){
    QByteArray Data = socket->readAll();

    QString DataStr = QString(Data);

    qDebug() << socketDescriptor << " Data in: " << DataStr;

    //socket->write(Data);
}

void Thread::disconnected(){

    qDebug() << socketDescriptor << " Disconnected";
    socket->deleteLater();

    exit(0);
}
