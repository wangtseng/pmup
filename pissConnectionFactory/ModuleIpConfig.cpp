#include "ModuleIpConfig.h"

ModuleIpConfig::ModuleIpConfig()
{

}

//--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief ModuleIpConfig::setModuleNumber
//! \param moduleNumber
//!
void ModuleIpConfig::setModuleNumber(int moduleNumber){
    this->moduleNumber = moduleNumber;
    switch (moduleNumber){
        case PISS:
            setName("piss");
            break;
        case CCISS:
            setName("cciss");
            break;
        case MISS:
            setName("miss");
            break;
        default:
            break;
    }
}

//--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief ModuleIpConfig::getIpAddress
//! \return
//!
QHostAddress ModuleIpConfig::getIpAddress()
{
    return this->addr;
}

//--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief ModuleIpConfig::getPort
//! \return
//!
int ModuleIpConfig::getPort()
{
    return this->port;
}

//--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief ModuleIpConfig::getModuleNumber
//! \return
//!
int ModuleIpConfig::getModuleNumber(){
    return this->moduleNumber;
}

//--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief ModuleIpConfig::getName
//! \return
//!
QString ModuleIpConfig::getName()
{
    return this->name;
}

//--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief ModuleIpConfig::getSocketrec
//! \return
//!
int ModuleIpConfig::getSocketrec()
{
    return this->socketrec;
}

//--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief ModuleIpConfig::getSocketTrans
//! \return
//!
int ModuleIpConfig::getSockettrans()
{
    return this->sockettrans;
}

//--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief ModuleIpConfig::getClientlistenport
//! \return
//!
quint32 ModuleIpConfig::getClientlistenport()
{
    return this->clientlistenport;
}

//--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief ModuleIpConfig::getCode
//! \return
//!
bool ModuleIpConfig::getCode()
{
    return this->code;
}



//--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief ModuleIpConfig::setIpAddress
//! \param Addr
//!
void ModuleIpConfig::setIpAddress(QHostAddress Addr)
{
    this->addr = Addr;
}

//--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief ModuleIpConfig::setPort
//! \param Port
//!
void ModuleIpConfig::setPort(int Port)
{
    this->port = Port;
}

//--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief ModuleIpConfig::setName
//! \param Name
//!
void ModuleIpConfig::setName(QString Name)
{
    this->name = Name;
}

//--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief ModuleIpConfig::setSocketrec
//! \param Socketrec
//!
void ModuleIpConfig::setSocketrec(int Socketrec)
{
    this->socketrec = Socketrec;
}

//--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief ModuleIpConfig::setSocketTrans
//! \param SocketTrans
//!
void ModuleIpConfig::setSockettrans(int Sockettrans)
{
    this->sockettrans = Sockettrans;
}

//--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief ModuleIpConfig::setClientlistenport
//! \param Clientlistenport
//!
void ModuleIpConfig::setClientlistenport(quint32 Clientlistenport)
{
    this->clientlistenport = Clientlistenport;
}

//--------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief ModuleIpConfig::setCode
//! \param Code
//!
void ModuleIpConfig::setCode(bool Code)
{
    this->code = Code;
}
