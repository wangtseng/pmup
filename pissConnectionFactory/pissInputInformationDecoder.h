#ifndef PISSINPUTINFORMATIONDECODER_H
#define PISSINPUTINFORMATIONDECODER_H

#include <QThread>
#include <QVector>
#include <QMutex>
#include "DatagrammeAnalyser.h"
#include "CDatagramme.h"

class pissInputInformationDecoder : public QThread
{
public:
    pissInputInformationDecoder(QVector <InputQueue*> *inputQueueManager,
                                pissNetworkEnvironment* NetworkEnvironment,
                                DatagrammeAnalyser *datagrammeAnalyser);
    ~pissInputInformationDecoder();
    void run();

private:
    pissNetworkEnvironment *networkEnvironment;
    QVector <InputQueue*> *inputQueueManager;
    DatagrammeAnalyser *datagrammeAnalyser;
    CDatagramme data;
    QMutex inputMutex;
};

#endif // PISSINPUTINFORMATIONDECODER_H
