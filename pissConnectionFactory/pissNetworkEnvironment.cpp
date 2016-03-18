#include "pissNetworkEnvironment.h"

pissNetworkEnvironment::pissNetworkEnvironment()
{
    this->clientCount = 0;
}

//!--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief pissNetworkEnvironment::addAClient
//!
void pissNetworkEnvironment::addAClient(){
    this->clientCount++;
}

//!--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief pissNetworkEnvironment::getClientNumber
//! \return
//!
int pissNetworkEnvironment::getClientNumber(){
    return this->clientCount;
}


//--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief pissNetworkEnvironment::selfDetectIP
//! \return
//!
QHostAddress pissNetworkEnvironment::selfDetectIP()
{
    foreach(const QHostAddress &address, QNetworkInterface::allAddresses())
    {
        if(address.protocol() == QAbstractSocket::IPv4Protocol && address != QHostAddress(QHostAddress::LocalHost))
            return address;
    }
}

//--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief pissNetworkEnvironment::init
//! \param Module
//! \param Port
//!
void pissNetworkEnvironment::append(QString ModuleName, int Port)
{
    if(ModuleName == "self")
    {
        ModuleIpConfig* selfIpConfig = new ModuleIpConfig();
        selfIpConfig->setIpAddress(this->selfDetectIP());
        selfIpConfig->setPort(Port);
        selfIpConfig->setName(ModuleName);
        selfIpConfig->setCode(0);
        mutex.lock();
        this->modules.append(selfIpConfig);
        mutex.unlock();
    }
}

//--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief pissNetworkEnvironment::init
//! \param ModuleName
//! \param Port
//! \param addr
//! \param Socketrec
//! \param Clientlistenport
//! \param Code
//!
void pissNetworkEnvironment::append(QString ModuleName,
                                    int Port,
                                    QString addr,
                                    int Socketrec,
                                    quint32 Clientlistenport,
                                    quint8 Code)
{
    mutex.lock();
    QHostAddress address(addr);
    ModuleIpConfig *missIpConfig = new ModuleIpConfig();
    missIpConfig->setIpAddress(address);
    missIpConfig->setPort(Port);
    missIpConfig->setName(ModuleName);
    missIpConfig->setSocketrec(Socketrec);
    missIpConfig->setClientlistenport(Clientlistenport);
    missIpConfig->setCode(Code);
    this->modules.append(missIpConfig);
    mutex.unlock();
}

//--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief pissNetworkEnvironment::append
//! \param ModuleNumber
//! \param Port
//! \param addr
//! \param Socketrec
//! \param Clientlistenport
//! \param Code
//!
void pissNetworkEnvironment::append(int ModuleNumber,
                                    int Port,
                                    QString addr,
                                    int Socketrec,
                                    quint32 Clientlistenport,
                                    quint8 Code){
    mutex.lock();
    QHostAddress address(addr);
    ModuleIpConfig *missIpConfig = new ModuleIpConfig();
    missIpConfig->setIpAddress(address);
    missIpConfig->setPort(Port);
    missIpConfig->setModuleNumber(ModuleNumber);
    missIpConfig->setSocketrec(Socketrec);
    missIpConfig->setClientlistenport(Clientlistenport);
    missIpConfig->setCode(Code);
    this->modules.append(missIpConfig);
    mutex.unlock();

}


//--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief pissNetworkEnvironment::setModuleName
//! \param ModuleName
//!
void pissNetworkEnvironment::setModuleName(QString ModuleName)
{
    this->moduleName = ModuleName;
}

void pissNetworkEnvironment::setSockettransByModule(QString ModuleName, int Sockettrans)
{
    mutex.lock();
    for(unsigned char cpt = 0; cpt < this->modules.size(); cpt++)
    {
        if(this->modules.at(cpt)->getName() == ModuleName)
        {
            this->modules.at(cpt)->setSockettrans(Sockettrans);
        }
    }
    mutex.unlock();
}

void pissNetworkEnvironment::setIpAddressByModule(QString ModuleName, QHostAddress ip)
{
    mutex.lock();
    for(unsigned char cpt = 0; cpt < this->modules.size(); cpt++)
    {
        if(this->modules.at(cpt)->getName() == ModuleName)
        {
            this->modules.at(cpt)->setIpAddress(ip);
        }
    }
    mutex.unlock();
}

void pissNetworkEnvironment::setClientlistenportByModule(QString ModuleName, quint32 Clientlistenport)
{
    mutex.lock();
    for(unsigned char cpt = 0; cpt < this->modules.size(); cpt++)
    {
        if(this->modules.at(cpt)->getName() == ModuleName)
        {
            this->modules.at(cpt)->setClientlistenport(Clientlistenport);
        }
    }
    mutex.unlock();
}

void pissNetworkEnvironment::setCodeByModule(QString ModuleName, bool Code)
{
    mutex.lock();
    for(unsigned char cpt = 0; cpt < this->modules.size(); cpt++)
    {
        if(this->modules.at(cpt)->getName() == ModuleName)
        {
            this->modules.at(cpt)->setCode(Code);
        }
    }
    mutex.unlock();
}




//--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief pissNetworkEnvironment::getIpAddressByModule
//! \param moduleName
//! \return
//!
QHostAddress pissNetworkEnvironment::getIpAddressByModule(QString ModuleName)
{
    QHostAddress ret;
    mutex.lock();
    for(unsigned char cpt = 0; cpt < this->modules.size(); cpt++)
    {
        if(this->modules.at(cpt)->getName() == ModuleName)
        {
            ret =  this->modules.at(cpt)->getIpAddress();
        }
    }
    mutex.unlock();
    return ret;
}

//--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief pissNetworkEnvironment::getIpAddressByModule
//! \param ModuleNumber
//! \return
//!
QHostAddress pissNetworkEnvironment::getIpAddressByModule(int ModuleNumber){
    QHostAddress ret;
    mutex.lock();
    for(unsigned char cpt = 0; cpt < this->modules.size(); cpt++)
    {
        if(this->modules.at(cpt)->getModuleNumber() == ModuleNumber)
        {
            ret =  this->modules.at(cpt)->getIpAddress();
        }
    }
    mutex.unlock();
    return ret;
}

//--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief pissNetworkEnvironment::getPortByModule
//! \param moduleName
//! \return
//!
int pissNetworkEnvironment::getPortByModule(QString ModuleName)
{
    int ret = -1;
    mutex.lock();
    for(unsigned char cpt = 0; cpt < this->modules.size(); cpt++)
    {
        if(this->modules.at(cpt)->getName() == ModuleName)
        {
            ret = this->modules.at(cpt)->getPort();
        }
    }
    mutex.unlock();
    return ret;
}

//--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief pissNetworkEnvironment::getPortByModule
//! \param ModuleNumber
//! \return
//!
int pissNetworkEnvironment::getPortByModule(int ModuleNumber){
    int ret = -1;
    mutex.lock();
    for(unsigned char cpt = 0; cpt < this->modules.size(); cpt++)
    {
        if(this->modules.at(cpt)->getModuleNumber() == ModuleNumber)
        {
            ret = this->modules.at(cpt)->getPort();
        }
    }
    mutex.unlock();
    return ret;
}

//--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief pissNetworkEnvironment::getSocketrecByModule
//! \param ModuleName
//! \return
//!
int pissNetworkEnvironment::getSocketrecByModule(QString ModuleName)
{
    //mutex.lock();
    for(unsigned char cpt = 0; cpt < this->modules.size(); cpt++)
    {
        if(this->modules.at(cpt)->getName() == ModuleName)
        {
            return this->modules.at(cpt)->getSocketrec();
        }
    }
    //mutex.unlock();
}

int pissNetworkEnvironment::getSockettransByModule(QString ModuleName)
{
    mutex.lock();
    for(unsigned char cpt = 0; cpt < this->modules.size(); cpt++)
    {
        if(this->modules.at(cpt)->getName() == ModuleName)
        {
            return this->modules.at(cpt)->getSockettrans();
        }
    }
    mutex.unlock();
}

int pissNetworkEnvironment::getSockettransByCode(quint8 Code)
{
    mutex.lock();
    for(unsigned char cpt = 0; cpt < this->modules.size(); cpt++)
    {
        if(this->modules.at(cpt)->getCode() == Code)
        {
            return this->modules.at(cpt)->getSockettrans();
        }
    }
    mutex.unlock();
}

quint32 pissNetworkEnvironment::getClientlistenportByModule(QString ModuleName)
{
    mutex.lock();
    for(unsigned char cpt = 0; cpt < this->modules.size(); cpt++)
    {
        if(this->modules.at(cpt)->getName() == ModuleName)
        {
            return this->modules.at(cpt)->getClientlistenport();
        }
    }
    mutex.unlock();
}

bool pissNetworkEnvironment::getCodeByModule(QString ModuleName)
{
    mutex.lock();
    for(unsigned char cpt = 0; cpt < this->modules.size(); cpt++)
    {
        if(this->modules.at(cpt)->getName() == ModuleName)
        {
            return this->modules.at(cpt)->getCode();
        }
    }
    mutex.unlock();
}
