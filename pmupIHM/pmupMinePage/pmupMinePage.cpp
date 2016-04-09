#include "pmupMinePage.h"


/**
 * @brief pmupMinePage::pmupMinePage
 * @param parent
 */
pmupMinePage::pmupMinePage(QWidget *parent) : QWidget(parent)
{
    this->setStyleSheet("background-color:aliceblue");
}

//! ------------------------------------------------------------------------
//!
//! \brief pmupMinePage::setSize
//! \param width
//! \param height
//!
void pmupMinePage::setSize(int width, int height){
    this->width = width;
    this->height = height;
    this->setFixedSize(this->width, this->height);
}

//! ------------------------------------------------------------------------
//!
//! \brief pmupMinePage::init
//!
void pmupMinePage::init(){

}

//! ------------------------------------------------------------------------
//!
//! \brief pmupMinePage::construct
//!
void pmupMinePage::construct(){

}

//! ------------------------------------------------------------------------
//!
//! \brief pmupMinePage::setConnection
//!
void pmupMinePage::setConnection(){

}
