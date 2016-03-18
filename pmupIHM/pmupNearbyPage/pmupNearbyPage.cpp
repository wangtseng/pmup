#include "pmupNearbyPage.h"

pmupNearbyPage::pmupNearbyPage(QWidget *parent) : QWidget(parent)
{
    this->setStyleSheet("background-color:beige");
}

void pmupNearbyPage::setSize(int width, int height){
    this->width = width;
    this->height = height;
    this->setFixedSize(this->width, this->height);
}
