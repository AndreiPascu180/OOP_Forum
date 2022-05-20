#include "protocoldislikeanswer.h"

ProtocolDislikeAnswer::ProtocolDislikeAnswer(QString Text)
{
    this->Text=Text;
}

void ProtocolDislikeAnswer::createMessage()
{
    //Text.resize(Text.size()-2);
    if(searchAnswerOrQuestion("Answers",Text))
    {
        QSqlQuery query;
        query.prepare("update Answers set Reputation-=1 where Text='"+Text+"'");
        query.exec();
        query.next();

        Message="12|1";
    }
    else
        Message="12|0";

}
void ProtocolDislikeAnswer::writeOnSocket(QTcpSocket* socket,DataBase db)
{
    db.getDataBase().open();
    this->createMessage();
    db.getDataBase().close();
    socket->write(Message);
}
