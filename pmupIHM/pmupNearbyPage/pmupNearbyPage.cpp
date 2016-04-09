#include "pmupNearbyPage.h"

pmupNearbyPage::pmupNearbyPage(QWidget *parent) : QWidget(parent)
{
    this->setStyleSheet("background-color:aliceblue");
}

//! ---------------------------------------------------------------------------
//!
//! \brief pmupNearbyPage::setSize
//! \param width
//! \param height
//!
void pmupNearbyPage::setSize(int width, int height){
    this->width = width;
    this->height = height;
    this->setFixedSize(this->width, this->height);
}

//! ---------------------------------------------------------------------------
//!
//! \brief pmupNearbyPage::init
//!
void pmupNearbyPage::init(){

}

//! ---------------------------------------------------------------------------
//!
//! \brief pmupNearbyPage::construct
//!
void pmupNearbyPage::construct(){

}

//! ---------------------------------------------------------------------------
//!
//! \brief pmupNearbyPage::setConnection
//!
void pmupNearbyPage::setConnection(){

}
