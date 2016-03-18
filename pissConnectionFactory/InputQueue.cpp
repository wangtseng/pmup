#include "InputQueue.h"

InputQueue::InputQueue()
{

}

InputQueue::~InputQueue()
{

}

void InputQueue::append(CDatagramme *datagramme){
    inputqueue.append(datagramme);
}

void InputQueue::clear(){
    inputqueue.clear();
}

void InputQueue::deleteFirstDatagramme(){
    inputqueue.pop_front();
}

CDatagramme* InputQueue::fetchFirstDatagramme(){
    return inputqueue.at(0);
}

int InputQueue::getLength(){
    return inputqueue.size();
}
