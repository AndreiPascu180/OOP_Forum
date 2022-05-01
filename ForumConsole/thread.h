#ifndef THREAD_H
#define THREAD_H

#include <QThread>
#include <QObject>
#include <QTcpSocket>
#include <QDebug>
#include "DataBase.h"

class Thread : public QThread
{
    Q_OBJECT
public:
    explicit Thread(qintptr ID, QObject *parent = nullptr) : QThread(parent){
        this->socketDescriptor = ID;
    }
    void run();

private:
    QTcpSocket *socket;
    qintptr socketDescriptor;
    DataBase db;

signals:
    //void Error(QTcpSocket::SocketError socketError);

public slots:
    void readyRead();
    void disconnected();
};

#endif // THREAD_H
