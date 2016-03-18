#include "pissServer.h"

/**
 * @brief pissServer::pissServer
 * @param inputQueueManager
 * @param NetworkEnvironment
 * @param datagrammeAnalyser
 */
pissServer::pissServer(QVector <InputQueue*> *inputQueueManager,
                       QVector <OutputQueue*> *outputQueueManager,
                       pissNetworkEnvironment *networkEnvironment,
                       DatagrammeAnalyser *datagrammeAnalyser,
                       GlobalTime *globalTime)
{
    this->serverStatus = false;
    this->id = 0;
    this->inputQueueManager = inputQueueManager;
    this->outputQueueManager = outputQueueManager;
    this->networkEnvironment = networkEnvironment;
    this->datagrammeAnalyser = datagrammeAnalyser;
    this->globalTime = globalTime;
}

//!--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief pissServer::~pissServer
//!
pissServer::~pissServer(){

}

//!--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief pissServer::launchServer
//!
void pissServer::launchServer(){
    serverStatus = this->listen(QHostAddress::Any, this->networkEnvironment->getPortByModule("self"));
}

//!--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief pissServer::getConnectionState
//!
bool pissServer::getConnectionState(){
    return serverStatus;
}

//!--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief pissServer::incomingConnection
//! \param socketDescriptor
//!
void pissServer::incomingConnection(qintptr socketDescriptor){ 
    this->networkEnvironment->addAClient();

    InputQueue *myInputQueue = new InputQueue();
    myInputQueue->clear();
    OutputQueue *myOutputQueue = new OutputQueue();
    myOutputQueue->clear();

    inputQueueManager->push_back(myInputQueue);
    outputQueueManager->push_back(myOutputQueue);

    pissReceptionTask *receptionTask = new pissReceptionTask(id,
                                                             socketDescriptor,
                                                             datagrammeAnalyser,
                                                             inputQueueManager,
                                                             networkEnvironment);

    receptionTask->start();

    id++;
}
