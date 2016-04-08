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
}

void AdvertisementArea::constructIHM(){

    xdInfomationLabel = new QPushButton();
    xdInfomationLabel->setFixedSize(width*0.3, height*0.07);
    xdInfomationLabel->setIconSize(QSize(width*0.25, height*0.05));
    xdInfomationLabel->setIcon(QIcon(":/images/info.png"));

    xdInfomationEdit = new QLineEdit();
    xdInfomationEdit->setStyleSheet("QLineEdit {border: 1px solid mediumspringgreen;border-radius: 0px; background: white;selection-background-color: darkgray;}");
    xdInfomationEdit->setFixedSize(width*0.7, height*0.07);

    xdInfomationBar = new QLabel();
    xdInfomationBar->setFixedHeight(height*0.07);
    xdInfomationBarLayout = new QHBoxLayout(xdInfomationBar);
    xdInfomationBarLayout->addWidget(xdInfomationLabel);
    xdInfomationBarLayout->addWidget(xdInfomationEdit);
    xdInfomationBarLayout->setSpacing(0);
    xdInfomationBarLayout->setMargin(0);

    xdPopularArea = new QWidget();
    xdPopularArea->setFixedHeight(height*0.93);

    myLayout = new QVBoxLayout(this);
    myLayout->addWidget(xdInfomationBar);
    myLayout->addWidget(xdPopularArea);
    myLayout->setSpacing(0);
    myLayout->setMargin(0);
}

void AdvertisementArea::setConnection(){

}
