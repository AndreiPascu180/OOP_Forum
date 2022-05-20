#include "protocollikeanswer.h"

ProtocolLikeAnswer::ProtocolLikeAnswer(QString Text)
{
    this->Text=Text;
}

void ProtocolLikeAnswer::createMessage()
{
    Text.resize(Text.size()-2);
    qDebug()<<Text;
    if(searchAnswerOrQuestion("Answers",Text)==true)
    {
        QSqlQuery query;
        query.prepare("update Answers set Reputation+=1 where Text='"+Text+"'");
        query.exec();
        query.next();
        Message="11|1";
    }
    else
        Message="11|0";
}
void ProtocolLikeAnswer::writeOnSocket(QTcpSocket* socket,DataBase db)
{
    db.getDataBase().open();
    this->createMessage();
    db.getDataBase().close();
    socket->write(Message);
}
