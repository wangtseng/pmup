#ifndef PISSCOMMUNICATIONSTACK_H
#define PISSCOMMUNICATIONSTACK_H

#include "pissInputInformationDecoder.h"
#include "pissNetworkEnvironment.h"
#include "DatagrammeAnalyser.h"
#include "InputQueue.h"
#include "OutputQueue.h"
#include "pissServer.h"
#include "GlobalTime.h"


class pissCommunicationStack
{
private:
    pissNetworkEnvironment *networkEnvironment;
    QVector <InputQueue*> inputQueueManager;
    QVector <OutputQueue*> outputQueueManager;
    DatagrammeAnalyser *datagrammeAnalyser;
    pissInputInformationDecoder *informationDecodeTask;
    pissServer *server;
    GlobalTime *globalTime;

public:
    void clearBuffer();
    void launch();

public:
    pissCommunicationStack(GlobalTime *globalTime);
};

#endif // PISSCOMMUNICATIONSTACK_H
