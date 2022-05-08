#include "protocol.h"

Protocol::Protocol(QObject *parent)
    : QObject{parent}
{

}
 DataBase db;
void Protocol::startDatabase()
{
    db.ConnectDB();
}

void Protocol::stopDatabase()
{
    db.getDataBase().close();
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

bool searchUsername(QString Username)
{
    QSqlQuery query;
    query.prepare("select* from Credentials where Username='"+Username+"'");
    query.exec();
    while(query.next())
    {
        return true;
    }
    return false;

}

bool searchQuestion(QString Question)
{
    QSqlQuery query;
    query.prepare("select * from Questions where Text='"+Question+"'");
    query.exec();

    while(query.next())
    {
        return true;
    }
    return false;

}

bool searchAnswer(QString Answer)
{
    QSqlQuery query;
    query.prepare("select * from Answers where Text='"+Answer+"'");
    query.exec();

    while(query.next())
    {
        return true;
    }
    return false;

}

QByteArray Protocol::LogIn(QString Username,QString Password)
{
    QByteArray Message;
    Password.resize(Password.size()-2);
    db.getDataBase().open();
    if(searchUser(Username,Password))
    {
        Message="1|1";
    }
    else
    {
        Message="1|0";
    }
    db.getDataBase().close();
    return Message;
}

QByteArray Protocol::Register(QString Username, QString Password, QString Email)
{
    QByteArray Message;
    Email.resize(Email.size()-2);
    db.getDataBase().open();
    if(searchUsername(Username))
    {
        Message="2|0";
    }
    else
    {
        QSqlQuery query;
        query.prepare("INSERT INTO [FORUM].[dbo].[Credentials](Username,Password,Email)  values (:Username,:Password,:Email)") ;
        query.bindValue(":Username",Username);
        query.bindValue(":Password",Password);
        query.bindValue(":Email",Email);

        if(query.exec())
            Message="2|1";
        else
            Message="2|0";
    }
    db.getDataBase().close();
    return Message;
}

QByteArray Protocol::PrintQuestions(QString TopicName)
{
    QByteArray Message="3|";
    QSqlQuery query,countQuery;
    db.getDataBase().open();
    TopicName.resize(TopicName.size()-2);

    countQuery.prepare("select count(*) from Questions Q inner join Topics T on T.IdTopic=Q.IdTopic where T.Name='"+TopicName+"'");
    countQuery.exec();

    query.prepare("select C.Username,Q.Text from Questions Q inner join Topics T on T.IdTopic=Q.IdTopic inner join Credentials C on C.IdUser=Q.IdUser where T.Name='"+TopicName+"'");
    query.exec();
    countQuery.next();

    Message+=countQuery.value(0).toByteArray()+"|";
    while(query.next())
    {
        Message+=query.value(0).toByteArray()+"|"+query.value(1).toByteArray()+"|";
    }
    db.getDataBase().close();
    return Message;
}

QByteArray Protocol::PrintAnswers(QString Question)
{
    QByteArray Message="4|";
    QSqlQuery query,countQuery;
    db.getDataBase().open();
    Question.resize(Question.size()-2);

    countQuery.prepare("select count(*) from Answers A inner join Questions Q on A.IdQuestion=Q.IdQuestion where Q.Text='"+Question+"'");
    countQuery.exec();

    query.prepare("select C.Username,A.Text from Answers A join Questions Q on Q.IdQuestion=A.IdQuestion join Credentials C on C.IdUser=A.IdUser where Q.Text='"+Question+"'");
    query.exec();
    countQuery.next();

    Message+=countQuery.value(0).toByteArray()+"|";
    while(query.next())
    {
        Message+=query.value(0).toByteArray()+"|"+query.value(1).toByteArray()+"|";
    }
    db.getDataBase().close();
    return Message;
}
QByteArray Protocol::SubmitQuestion(QString Username,QString TopicName, QString Question)
{
    QByteArray Message;
    QSqlQuery query;
    db.getDataBase().open();
    Question.resize(Question.size()-2);

    query.prepare("declare @Id1 as int;declare @Id2 as int;select @Id1=C.IdUser from Credentials C where Username='"+Username+"'; select @Id2=T.IdTopic from Topics T where T.Name='"+TopicName+"';insert into FORUM.dbo.Questions (IdUser,IdTopic,Text) values (@Id1,@Id2,:Question)") ;
    query.bindValue(":Question",Question);

    if(query.exec())
        Message="5|1";
    else
        Message="5|0";
    db.getDataBase().close();
    return Message;
}

QByteArray Protocol::SubmitAnswer(QString Username,QString Question, QString Answer)
{
    QByteArray Message;
    QSqlQuery query;
    db.getDataBase().open();
    Answer.resize(Answer.size()-2);

    query.prepare("declare @Id1 as int;declare @Id2 as int;select @Id1=C.IdUser from Credentials C where Username='"+Username+"'; select @Id2=Q.IdQuestion from Questions Q where Q.Text='"+Question+"';insert into FORUM.dbo.Answers (IdUser,IdQuestion,Text) values (@Id1,@Id2,:Answer)") ;
    query.bindValue(":Answer",Answer);

    if(query.exec())
        Message="6|1";
    else
        Message="6|0";
    db.getDataBase().close();
    return Message;
}

QByteArray Protocol::EditQuestion(QString OldQuestion, QString NewQuestion)
{
    QByteArray Message;
    QSqlQuery query;

    db.getDataBase().open();
    NewQuestion.resize(NewQuestion.size()-2);

    if(searchQuestion(OldQuestion)==true)
    {
        query.prepare("Update FORUM.dbo.Questions set Text=:NewQuestion where Text='"+OldQuestion+"'");
        query.bindValue(":NewQuestion",NewQuestion);
        query.exec();
        Message="7|1";
    }
    else
        Message="7|0";
    db.getDataBase().close();
    return Message;
}


QByteArray Protocol::EditAnswer(QString OldAnswer, QString NewAnswer)
{
    QByteArray Message;
    QSqlQuery query;

    db.getDataBase().open();
    NewAnswer.resize(NewAnswer.size()-2);

    if(searchAnswer(OldAnswer)==true)
    {
        query.prepare("Update FORUM.dbo.Answers set Text=:NewAnswer where Text='"+OldAnswer+"'");
        query.bindValue(":NewAnswer",NewAnswer);
        query.exec();
        Message="8|1";
    }
    else
        Message="8|0";

    db.getDataBase().close();
    return Message;
}

QByteArray Protocol::DeleteQuestion(QString Question)
{

    QByteArray Message;
    QSqlQuery query;

    db.getDataBase().open();
    Question.resize(Question.size()-2);

    if(searchQuestion(Question)==true)
    {
        query.prepare("declare @IdQ int;select @IdQ=IdQuestion from Questions where Text='"+Question+"'; delete from Answers where IdQuestion=@IdQ;delete from Questions where IdQuestion=@IdQ");
        query.exec();
        Message="9|1";
    }
    else
        Message="9|0";

    db.getDataBase().close();
    return Message;
}

QByteArray Protocol::DeleteAnswer(QString Answer)
{

    QByteArray Message;
    QSqlQuery query;

    db.getDataBase().open();
    Answer.resize(Answer.size()-2);

    if(searchAnswer(Answer)==true)
    {
        query.prepare("declare @IdA int;select @IdA=IdAnswer from Answers where Text='"+Answer+"'; delete from Answers where IdAnswer=@IdA;");
        query.exec();
        Message="10|1";
    }
    else
        Message="10|0";

    db.getDataBase().close();
    return Message;
}

