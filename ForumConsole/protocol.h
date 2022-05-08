#ifndef PROTOCOL_H
#define PROTOCOL_H
#include "database.h"
#include <QObject>

class Protocol : public QObject
{
    Q_OBJECT
public:
    explicit Protocol(QObject *parent = nullptr);
    static void startDatabase();
    static void stopDatabase();
    static QByteArray LogIn(QString Username, QString Password);
    static QByteArray Register(QString Username, QString Password, QString Email);
    static QByteArray PrintQuestions(QString TopicName);
    static QByteArray PrintAnswers(QString Question);
    static QByteArray SubmitQuestion(QString Username,QString TopicName,QString Question);
    static QByteArray SubmitAnswer(QString Username,QString Question,QString Answer);
    static QByteArray EditQuestion (QString OldQuestion,QString NewQuestion);
    static QByteArray EditAnswer (QString OldAnswer,QString NewAnswer);
    static QByteArray DeleteQuestion(QString Question);
    static QByteArray DeleteAnswer(QString Answer);


private:


signals:

};

#endif // PROTOCOL_H
