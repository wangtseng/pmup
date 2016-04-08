#include "AdvertisementArea.h"

AdvertisementArea::AdvertisementArea(int width, int height) : QFrame()
{
    this->width = width;
    this->height = height;
    this->initVariable();
    this->constructIHM();
    this->setConnection();
}

void AdvertisementArea::initVariable(){
    this->setFixedSize(this->width, this->height);
    //this->setStyleSheet("background-color:cyan");
}

void AdvertisementArea::constructIHM(){

}

void AdvertisementArea::setConnection(){

}
