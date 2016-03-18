#ifndef PISSSERVER_H
#define PISSSERVER_H

#include <QTcpServer>
#include <QVector>
#include "pissNetworkEnvironment.h"
#include "pissReceptionTask.h"
#include "DatagrammeAnalyser.h"
#include "pissInputInformationDecoder.h"


class pissServer : public QTcpServer
{
    Q_OBJECT
public:
    pissServer(QVector <InputQueue*> *inputQueueManager,
               QVector <OutputQueue*> *outputQueueManager,
               pissNetworkEnvironment* networkEnvironment,
               DatagrammeAnalyser *datagrammeAnalyser,
               GlobalTime *globalTime);

    ~pissServer();
    void launchServer();
    bool getConnectionState();

private:

    bool serverStatus;

    pissNetworkEnvironment *networkEnvironment;
    QVector <InputQueue*> *inputQueueManager;
    QVector <OutputQueue*> *outputQueueManager;
    DatagrammeAnalyser *datagrammeAnalyser;
    GlobalTime *globalTime;

protected:
    int id;
    void incomingConnection(qintptr socket);
};

#endif // PISSSERVER_H
