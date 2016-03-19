#include "pmupFirstPage.h"

/**
 * @brief pmupFirstPage::pmupFirstPage
 * @param parent
 */
pmupFirstPage::pmupFirstPage(QWidget *parent) : QWidget(parent){
    this->setStyleSheet("background-color:beige;");
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
    titleBar->setFixedHeight(this->height*0.06);

    cityOption = new QComboBox();
    cityOption->setFixedSize(this->width*0.2, this->height*0.06);
    cityOption->setStyleSheet("QComboBox {border: 0px solid gray;border-radius: 3px;padding: 1px 18px 1px 3px;min-width: 6em; color: mediumspringgrenn}"
                              "QComboBox::drop-down { subcontrol-origin: padding;subcontrol-position: top right;width: 15px;border-left-width: 1px; border-left-color: lightGray; border-left-style: solid;border-top-right-radius: 3px; border-bottom-right-radius: 3px;}"
                              "QComboBox::down-arrow {border-image: url(:/down_arrow.png); } "
                              "QComboBox::down-arrow:on {top: 1px; left: 1px;}");

    fillCityOptions(cityOption, this->width*0.1, this->height*0.06);

    serchingArea = new QLineEdit();
    serchingArea->setFixedSize(this->width*0.6, this->height*0.06);
    serchingArea->setStyleSheet("QLineEdit {border: 0px solid orange; background-color: aliceblue; selection-background-color: darkgray;}");

    searchingButton = new QToolButton();
    searchingButton->setFixedSize(this->height*0.1, this->height*0.06);

    scanQCodeButton = new QToolButton();
    scanQCodeButton->setFixedSize(this->height*0.1, this->height*0.06);

    titleBarLayout = new QHBoxLayout(titleBar);
    titleBarLayout->addWidget(cityOption);
    titleBarLayout->addWidget(serchingArea);
    titleBarLayout->addWidget(searchingButton);
    titleBarLayout->addWidget(scanQCodeButton);
    titleBarLayout->setSpacing(0);
    titleBarLayout->setMargin(0);

    rankingLabel = new QLabel();
    rankingLabel->setFixedWidth(int(this->width*0.15));

    subjectsArea = new pmupSubjectsPage(int(this->width*0.85), int(this->height*0.3));

    popularWidget = new QWidget();
    popularWidgetLayout = new QHBoxLayout(popularWidget);
    popularWidgetLayout->addWidget(rankingLabel);
    popularWidgetLayout->addWidget(subjectsArea);
    popularWidgetLayout->setSpacing(0);
    popularWidgetLayout->setMargin(0);

    advertisementArea = new QWidget();
    advertisementArea->setFixedHeight(this->height*0.64);

    myLayout = new QVBoxLayout(this);
    myLayout->addWidget(titleBar);
    myLayout->addWidget(popularWidget);
    myLayout->addWidget(advertisementArea);
    myLayout->setSpacing(0);
    myLayout->setMargin(0);
}

void pmupFirstPage::fillCityOptions(QComboBox *cityOption, int width, int height){
    QStringList city_list;
    QStringList color_list;
    city_list<<"澳门"<<"珠海";
    color_list<<"green"<<"red";
    for(int cpt = 0; cpt < color_list.size(); cpt++){
        QPixmap *pix = new QPixmap(QSize(width, height));
        pix->fill(QColor(color_list.at(cpt)));
        cityOption->addItem(QIcon(*pix), city_list.at(cpt));
        cityOption->setIconSize(QSize(width,height));
        cityOption->setSizeAdjustPolicy(QComboBox::AdjustToContents);
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
