#include "pmupMinePage.h"

pmupMinePage::pmupMinePage(QWidget *parent) : QWidget(parent)
{
    this->setStyleSheet("background-color:beige");
}

void pmupMinePage::setSize(int width, int height){
    this->width = width;
    this->height = height;
    this->setFixedSize(this->width, this->height);
}
