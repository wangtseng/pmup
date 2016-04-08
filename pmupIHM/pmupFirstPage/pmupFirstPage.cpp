#include "pmupFirstPage.h"

/**
 * @brief pmupFirstPage::pmupFirstPage
 * @param parent
 */
pmupFirstPage::pmupFirstPage(QWidget *parent) : QWidget(parent){
    this->setStyleSheet("background-color:beige; border: 0px solid gray;");
}

//!------------------------------------------------------------------------------------------------
//!
//! \brief pmupFirstPage::initVariable
//!
void pmupFirstPage::initVariable(){

}

//!------------------------------------------------------------------------------------------------
//!
//! \brief pmupFirstPage::constructIHM
//!
void pmupFirstPage::constructIHM(){
    //!--title bar of the fist page
    titleBar = new QLabel();
    titleBar->setFixedHeight(this->height*0.05);

    cityOption = new QComboBox();
    cityOption->setFixedSize(this->width*0.2, this->height*0.05);

    cityOption->setStyleSheet("QComboBox {border: 0px solid gray;border-radius: 0px;padding: 1px 0px 0px 0px; color: mediumspringgreen}"
                              "QComboBox::drop-down { subcontrol-origin: padding}"
                              "QComboBox QAbstractItemView::item{height:30px;}"
                              "QComboBox::down-arrow {border-image: url(:images/pen.png); } "
                              "QComboBox::up-arrow {image: url(:/images/pen.png);}");

    fillCityOptions(cityOption, this->width*0.08, this->height*0.05);

    serchingArea = new QLineEdit();
    serchingArea->setFixedSize(this->width*0.66, this->height*0.05);
    serchingArea->setStyleSheet("QLineEdit {border: 1px solid mediumspringgreen; color: mediumspringgreen;}");

    searchingButton = new QToolButton();
    searchingButton->setFixedSize(this->width*0.07, this->height*0.05);
    searchingButton->setIconSize(QSize(this->width*0.07, this->height*0.05));
    searchingButton->setIcon(QIcon(":/images/search.png"));

    scanQCodeButton = new QToolButton();
    scanQCodeButton->setFixedSize(this->width*0.07, this->height*0.05);
    scanQCodeButton->setIconSize(QSize(this->width*0.07, this->height*0.05));
    scanQCodeButton->setIcon(QIcon(":/images/scanning.png"));

    titleBarLayout = new QHBoxLayout(titleBar);
    titleBarLayout->addWidget(cityOption);
    titleBarLayout->addWidget(serchingArea);
    titleBarLayout->addWidget(searchingButton);
    titleBarLayout->addWidget(scanQCodeButton);
    titleBarLayout->setSpacing(0);
    titleBarLayout->setMargin(0);

    subjectsArea = new pmupSubjectsPage(this->width, int(this->height*0.3));

    advertisementArea = new AdvertisementArea(this->width, int(this->height*0.65));

    myLayout = new QVBoxLayout(this);
    myLayout->addWidget(titleBar);
    myLayout->addWidget(subjectsArea);
    myLayout->addWidget(advertisementArea);
    myLayout->setSpacing(0);
    myLayout->setMargin(0);
}

//! ---------------------------------------------------------------------------------------------
//!
//! \brief pmupFirstPage::fillCityOptions
//! \param cityOption
//! \param width
//! \param height
//!
void pmupFirstPage::fillCityOptions(QComboBox *cityOption, int width, int height){
    QStringList city_list;
    QStringList color_list;
    city_list<<"深圳"<<"珠海"<<"广州"<<"香港"<<"台湾"<<"澳门";
    color_list<<"skyblue"<<"orange"<<"yellow"<<"green"<<"cyan"<<"blue";
    for(int cpt = 0; cpt < color_list.size(); cpt++){
        QPixmap *pix = new QPixmap(QSize(width, height));
        pix->fill(QColor(color_list.at(cpt)));
        cityOption->addItem(QIcon(*pix), city_list.at(cpt));
        cityOption->setIconSize(QSize(width,height));
        //cityOption->setSizeAdjustPolicy(QComboBox::AdjustToContents);
    }
}

void pmupFirstPage::drawBackground(){

}

void pmupFirstPage::setConnections(){

}

void pmupFirstPage::setSize(int appWidth, int appHeight){
    this->width = appWidth;
    this->height = appHeight;
    this->setFixedSize(this->width, this->height);
    qDebug()<<this->width<<this->height;
    constructIHM();
}
