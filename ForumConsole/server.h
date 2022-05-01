#ifndef SERVER_H
#define SERVER_H
#include <QDebug>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include <QObject>
#include "thread.h"

class Server : public QTcpServer
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);
    void StartServer();

protected:
    void incomingConnection(qintptr socketDescriptor);
signals:

public slots:
       void newConnection();

private:
       QTcpServer *server;



};

#endif // SERVER_H
