#ifndef PROTOCOLLIKEANSWER_H
#define PROTOCOLLIKEANSWER_H

#include "cprotocol.h"

class ProtocolLikeAnswer : public CProtocol
{
public:

    ProtocolLikeAnswer(QString Text);
    virtual void writeOnSocket(QTcpSocket* socket,DataBase db);
    virtual void createMessage();

private:
    QString Text;
};


#endif // PROTOCOLLIKEANSWER_H
