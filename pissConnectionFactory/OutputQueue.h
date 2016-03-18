#ifndef OUTPUTQUEUE_H
#define OUTPUTQUEUE_H

#include<QList>
#include"CDatagramme.h"

class OutputQueue
{
public:
    OutputQueue();
    ~OutputQueue();

    void append(CDatagramme* datagramme);
    void clear();
    void deleteFrontElement();
    CDatagramme* fetchFirstDatagramme();
    int getLength();
private:
    QList <CDatagramme*> outputqueue;
};

#endif // OUTPUTQUEUE_H
