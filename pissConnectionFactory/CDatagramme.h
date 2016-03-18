#ifndef CDATAGRAMME_H
#define CDATAGRAMME_H

#include <string.h>
#include <cmath>
#include <QByteArray>
#include <qDebug>

class CDatagramme
{
public:

    CDatagramme();
    ~CDatagramme();

    void setValue(QByteArray* value);
    void modifierTimestamp(qint32 time);
    void printSelf();

    int getID();
    int getDLC();
    int getModuleNumber();

    QString getTimestamp();
    QByteArray *getValue();

private:
    int totalLength;
    QByteArray* value;
};

#endif // CDATAGRAMME_H
