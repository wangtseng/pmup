#include "SearchingArea.h"

SearchingArea::SearchingArea(QWidget *parent) : QWidget(parent)
{

}

void SearchingArea::initVariable(){

}

void SearchingArea::constructIHM(){
    searchingAreaLayout = new QVBoxLayout(this);
    searchingEdit = new QLineEdit();
    searchingEdit->setStyleSheet("QLineEdit {border: 2px solid gray;border-radius: 10px;padding: 0 8px; background: white;selection-background-color: darkgray;}");
    searchingEdit->setFixedSize(this->appWidth, this->appHeight);
    searchingAreaLayout->addWidget(searchingEdit);
    searchingAreaLayout->setSpacing(0);
}

void SearchingArea::drawBackground(){

}

void SearchingArea::setConnections(){

}

void SearchingArea::setSize(int appWidth, int appHeight){
    this->appWidth = appWidth;
    this->appHeight = appHeight;
    this->setFixedSize(this->appWidth, this->appHeight);
    this->initVariable();
    this->constructIHM();
    this->setConnections();
}
