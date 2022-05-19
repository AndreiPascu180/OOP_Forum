#ifndef CLIENT_H
#define CLIENT_H
#include "iclient.h"


class Client : public IClient
{
    Q_OBJECT
private:
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
