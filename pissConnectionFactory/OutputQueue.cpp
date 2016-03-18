#include "OutputQueue.h"

OutputQueue::OutputQueue()
{
}

OutputQueue::~OutputQueue()
{

}

void OutputQueue::append(CDatagramme *datagramme)
{
    outputqueue.append(datagramme);
}

void OutputQueue::clear(){
    outputqueue.clear();
}

void OutputQueue::deleteFrontElement()
{
    outputqueue.pop_front();
}

CDatagramme* OutputQueue::fetchFirstDatagramme()
{
    return outputqueue.at(0);
}

int OutputQueue::getLength(){
    return outputqueue.size();
}
