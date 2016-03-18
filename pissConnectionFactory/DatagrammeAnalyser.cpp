#include "DatagrammeAnalyser.h"

DatagrammeAnalyser::DatagrammeAnalyser(QVector <OutputQueue*> *oq,
                                       QVector <InputQueue*> *iq,
                                       pissNetworkEnvironment* environment,
                                       GlobalTime *globalTime)
{
    this->iq = iq;
    this->oq = oq;
    this->mNetworkEnvironment = environment;
    this->globalTime = globalTime;
}

DatagrammeAnalyser::~DatagrammeAnalyser()
{

}

void DatagrammeAnalyser::encodage(QString modulename)
{

}

void DatagrammeAnalyser::decodage(int id, CDatagramme *datagramme){

    switch (datagramme->getID()){
        case HelloMessage: {
            qDebug()<<"HelloMessage";
            decodeHelloMessage(id, datagramme);
            break;
        }
        case HandShakeMessage:{
            qDebug()<<"HandShakeMessage";
            decodeHandShakeMessage(id, datagramme);
            break;
        }
        case CTImage:{
            qDebug()<<"CTImage";
            decodeCTImage(datagramme);
            break;
        }
    }
    qDebug()<<"end decoding process";
}

void DatagrammeAnalyser::decodeHelloMessage(int id, CDatagramme *datagramme){

    //datagramme.modiferTimestamp(ccfgdfgfd)
    //globalTime->GetMicroS()

    oq->at(id)->append(datagramme);

}

void DatagrammeAnalyser::decodeHandShakeMessage(int id, CDatagramme *datagramme){
    QString moduleIpAddress;
    int port;
    int moduleNumber = id;


    moduleIpAddress = QString("%1.%2.%3.%4").arg(quint8(datagramme->getValue()->at(8))).arg(quint8(datagramme->getValue()->at(9))).arg(quint8(datagramme->getValue()->at(10))).arg(quint8(datagramme->getValue()->at(11)));
    port = datagramme->getValue()->at(12)*100 + datagramme->getValue()->at(13);
    mNetworkEnvironment->append(moduleNumber, port, moduleIpAddress, 0, 0, 1);

    pissTransmissionTask *transmissionTask = new pissTransmissionTask(oq, mNetworkEnvironment);
    transmissionTask->connectTo(moduleNumber);
}

void DatagrammeAnalyser::decodeCTImage(CDatagramme *datagramme){

}

