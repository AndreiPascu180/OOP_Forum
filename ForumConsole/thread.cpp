#include "thread.h"
//#include "DataBase.h"
#include "protocol.h"
#include <QString>


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

    Protocol::startDatabase();
    //db.ConnectDB();
    exec();
}


void Thread::readyRead(){
    QByteArray Data = socket->readAll();

    QStringList dataList= QString(Data).split('|');

    if(dataList.value(0)=="1")
        socket->write(Protocol::LogIn(dataList.value(1),dataList.value(2)));

    if(dataList.value(0)=="2")
        socket->write(Protocol::Register(dataList.value(1),dataList.value(2),dataList.value(3)));

    if(dataList.value(0)=="3")
        socket->write(Protocol::PrintQuestions(dataList.value(1)));

    if(dataList.value(0)=="4")
        socket->write(Protocol::PrintAnswers(dataList.value(1)));

    if(dataList.value(0)=="5")
        socket->write(Protocol::SubmitQuestion(dataList.value(1),dataList.value(2),dataList.value(3)));

    if(dataList.value(0)=="6")
        socket->write(Protocol::SubmitAnswer(dataList.value(1),dataList.value(2),dataList.value(3)));

    if(dataList.value(0)=="7")
        socket->write(Protocol::EditQuestion(dataList.value(1),dataList.value(2)));

    if(dataList.value(0)=="8")
        socket->write(Protocol::EditAnswer(dataList.value(1),dataList.value(2)));

    if(dataList.value(0)=="9")
        socket->write(Protocol::DeleteQuestion(dataList.value(1)));

    if(dataList.value(0)=="10")
        socket->write(Protocol::DeleteAnswer(dataList.value(1)));


}

void Thread::disconnected(){

    qDebug() << socketDescriptor << " Disconnected";
    socket->deleteLater();
   // Protocol::stopDatabase();
    exit(0);
}
