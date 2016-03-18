#include "CDatagramme.h"


/**
 * @brief CDatagramme::CDatagramme
 * @param value
 */
CDatagramme::CDatagramme(){

}

//!-------------------------------------------------------------
//!
//! \brief CDatagramme::~CDatagramme
//!
CDatagramme::~CDatagramme(){

}

//!-------------------------------------------------------------
//!
//! \brief CDatagramme::setValue
//! \param value
//!
void CDatagramme::setValue(QByteArray* value){
    this->value = value;
    this->totalLength = this->value->length();
}

QByteArray* CDatagramme::getValue(){
    return this->value;
}

void CDatagramme::printSelf(){
    qDebug()<<this->totalLength<<":"<<this->value;

}

//!-------------------------------------------------------------
//!
//! \brief CDatagramme::getIdentifierByte
//! \return
//!
int CDatagramme::getID(){
    return int(this->value->at(0));
}

void CDatagramme::modifierTimestamp(qint32 time){
    (*this->value)[1] = time % int(pow(2, 8));
    (*this->value)[2] = time / int(pow(2, 8)) % int(pow(2, 8));
    (*this->value)[3] = time / int(pow(2, 16)) % int(pow(2,8));
    (*this->value)[4] = time / int(pow(2, 24)) % int(pow(2,8));
}

QString CDatagramme::getTimestamp()
{
    return QString("%1%2%3%4").arg(quint8(this->value->at(1))).arg(quint8(this->value->at(2))).arg(quint8(this->value->at(3))).arg(quint8(this->value->at(4)));
}

int CDatagramme::getDLC()
{
    return this->value->size() - 8;
}

int CDatagramme::getModuleNumber(){
    return int(this->value->at(7));
}
