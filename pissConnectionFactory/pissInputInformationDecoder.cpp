#include "pissInputInformationDecoder.h"

pissInputInformationDecoder::pissInputInformationDecoder(QVector<InputQueue *> *inputQueueManager,
                                                         pissNetworkEnvironment *NetworkEnvironment,
                                                         DatagrammeAnalyser *datagrammeAnalyser)
{
    this->inputQueueManager = inputQueueManager;
    this->networkEnvironment = NetworkEnvironment;
    this->datagrammeAnalyser = datagrammeAnalyser;
}

pissInputInformationDecoder::~pissInputInformationDecoder(){

}

void pissInputInformationDecoder::run()
{
    while (true){
        inputMutex.lock();
        if(inputQueueManager->size()>0){
            for(unsigned char cpt = 0; cpt < inputQueueManager->size(); cpt++){
                int length = inputQueueManager->at(cpt)->getLength();
                if(length > 0){
                    datagrammeAnalyser->decodage(cpt, inputQueueManager->at(cpt)->fetchFirstDatagramme());
                    inputQueueManager->at(cpt)->deleteFirstDatagramme();
                }
                else{
                    //qDebug()<<"no message pushed into inputqueue at"<<cpt;
                }
            }
        }
        else{
            //qDebug()<<"no input queue generated";
        }

        inputMutex.unlock();
        usleep(20);
    }
}
