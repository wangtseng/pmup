#include "pissTransmissionTask.h"


pissTransmissionTask::pissTransmissionTask(QVector<OutputQueue *> *oq, pissNetworkEnvironment* environment){
    frameCounter = 0;
    transmissionTimer = new QTimer();
    this->oq = oq;
    this->environment = environment;
    this->socketTransmission = new QTcpSocket();
    this->connect(this->socketTransmission, SIGNAL(connected()), this, SLOT(startTransfer()));
    this->connect(this->transmissionTimer, SIGNAL(timeout()), this, SLOT(transfer()));
}

pissTransmissionTask::~pissTransmissionTask(){

}

void pissTransmissionTask::connectTo(int moduleNumber){
    this->socketTransmission->connectToHost(this->environment->getIpAddressByModule(moduleNumber),
                                            this->environment->getPortByModule(moduleNumber));
}

void pissTransmissionTask::startTransfer(){
    this->transmissionTimer->start(20);
}

void pissTransmissionTask::transfer(){
    outputMutex.lock();
    if(oq->size() > 0){
        for(unsigned int cpt = 0; cpt < oq->size(); cpt++){
            int length = oq->at(cpt)->getLength();
            if(length > 0)
            {
                this->socketTransmission->write(*(oq->at(cpt)->fetchFirstDatagramme()->getValue()));
                this->socketTransmission->waitForBytesWritten(-1);
                frameCounter ++;
            }
        }
    }
    outputMutex.unlock();
}
