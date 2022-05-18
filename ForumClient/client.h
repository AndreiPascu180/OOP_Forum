#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <string>
#include <QString>
#include <QObject>
#include <QTcpSocket>

class Client : public QObject
{
    Q_OBJECT
private:
    //std::string username;
    //std::string password;
    QTcpSocket *socket;
    QStringList lastResponseMsg;
    QString username;

public:
    explicit Client(QString ip, int port);
    QTcpSocket* getSocket();
    QStringList getLastMsg();
    void setUsername(QString user);
    QString getUsername();

signals:

public slots:
    void onReadyRead();

};

#endif // CLIENT_H
