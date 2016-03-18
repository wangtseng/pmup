#include "pmupCamaradePage.h"

pmupCamaradePage::pmupCamaradePage(QWidget *parent) : QWidget(parent)
{
    this->setStyleSheet("background-color:beige;");
}

void pmupCamaradePage::setSize(int width, int height){
    this->width = width;
    this->height = height;
    this->setFixedSize(this->width, this->height);
}
