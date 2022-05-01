#include "thread.h"
#include "DataBase.h"

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
    db.ConnectDB();

    exec();
}

bool searchUser(QString Username, QString Password)
{
    QSqlQuery query;

    query.prepare("select* from Credentials where Username='"+Username+"'and Password='"+Password+"'");

    query.exec();

    while(query.next())
    {
        return true;
    }
    return false;

}

void Thread::readyRead(){
    QByteArray Data = socket->readAll();

   // QString DataStr = QString(Data);
    //qDebug() << socketDescriptor << " Data in: " << DataStr;

    QStringList dataList= QString(Data).split('/');
    if(dataList.value(0)=="1")
    {
        db.getDataBase().open();
        if(searchUser(dataList.value(1),dataList.value(2)))
        {
            qDebug()<<"Date de logare corecte";
        }
        else
        {
            qDebug()<<"User sau Parola gresite";
        }

    }

    //socket->write(Data);
}

void Thread::disconnected(){

    qDebug() << socketDescriptor << " Disconnected";
    socket->deleteLater();

    exit(0);
}
