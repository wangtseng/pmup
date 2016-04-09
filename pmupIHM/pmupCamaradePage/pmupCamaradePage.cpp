#include "pmupCamaradePage.h"


/**
 * @brief pmupCamaradePage::pmupCamaradePage
 * @param parent
 */
pmupCamaradePage::pmupCamaradePage(QWidget *parent) : QWidget(parent)
{
    this->setStyleSheet("background-color:aliceblue;");
}

//! ----------------------------------------------------------------------
//!
//! \brief pmupCamaradePage::setSize
//! \param width
//! \param height
//!
void pmupCamaradePage::setSize(int width, int height){
    this->width = width;
    this->height = height;
    this->setFixedSize(this->width, this->height);
}

//! ----------------------------------------------------------------------
//!
//! \brief pmupCamaradePage::init
//!
void pmupCamaradePage::init(){

}

//! ----------------------------------------------------------------------
//!
//! \brief pmupCamaradePage::construct
//!
void pmupCamaradePage::construct(){

}

//! ----------------------------------------------------------------------
//!
//! \brief pmupCamaradePage::setConnection
//!
void pmupCamaradePage::setConnection(){

}
