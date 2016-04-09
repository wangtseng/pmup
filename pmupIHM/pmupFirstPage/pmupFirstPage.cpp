#include "pmupFirstPage.h"

/**
 * @brief pmupFirstPage::pmupFirstPage
 * @param parent
 */
pmupFirstPage::pmupFirstPage(QWidget *parent) : QWidget(parent){
    this->setStyleSheet("background-color:aliceblue; border: 0px solid gray;");
}

//!------------------------------------------------------------------------------------------------
//!
//! \brief pmupFirstPage::initVariable
//!
void pmupFirstPage::initVariable(){
    QImageReader reader(":/images/background.png");
    reader.setAutoTransform(true);
    newImage = reader.read();
}

//!------------------------------------------------------------------------------------------------
//!
//! \brief pmupFirstPage::constructIHM
//!
void pmupFirstPage::constructIHM(){
    //!--title bar of the fist page

    cityOption = new QComboBox();
    cityOption->setFont(QFont("Helvetica", 13, QFont::AnyStyle, false));
    cityOption->setFixedSize(this->width*0.12, this->height*0.04);

    cityOption->setStyleSheet("QComboBox {background-color: AliceBlue; border: 0px solid gray;border-radius: 0px;padding: 1px 0px 0px 0px; color: teal;}"
                              "QComboBox::drop-down { subcontrol-origin: padding}"
                              "QComboBox QAbstractItemView::item{height:30px;}"
                              "QComboBox::down-arrow {background-color: transparent; border-image: url(:images/pen.png); } "
                              "QComboBox::up-arrow {background-color: transparent; image: url(:/images/pen.png);}");

    fillCityOptions(cityOption, this->width*0.08, this->height*0.04);

    serchingArea = new QLineEdit();
    serchingArea->setFixedSize(this->width*0.62, this->height*0.05);
    serchingArea->setStyleSheet("QLineEdit {background-color: AliceBlue; border: 1px solid teal; color: teal;}");

    searchingButton = new QToolButton();
    searchingButton->setFixedSize(this->width*0.07, this->height*0.05);
    searchingButton->setIconSize(QSize(this->width*0.07, this->height*0.05));
    searchingButton->setIcon(QIcon(":/images/search.png"));
    searchingButton->setStyleSheet("background:transparent; ");

    scanQCodeButton = new QToolButton();
    scanQCodeButton->setFixedSize(this->width*0.07, this->height*0.05);
    scanQCodeButton->setIconSize(QSize(this->width*0.07, this->height*0.05));
    scanQCodeButton->setIcon(QIcon(":/images/scanning.png"));
    scanQCodeButton->setStyleSheet("background-color:AliceBlue");

    controlAreaItem = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Expanding);

//    titleBar = new QLabel();
//    titleBar->setStyleSheet("background-color:transparent;");
//    titleBar->setFixedSize(this->width*0.96, this->height*0.05);
//    titleBarLayout = new QHBoxLayout(titleBar);
//    titleBarLayout->addWidget(cityOption);
//    titleBarLayout->addWidget(serchingArea);
//    titleBarLayout->addWidget(searchingButton);
//    titleBarLayout->addWidget(scanQCodeButton);
//    titleBarLayout->setSpacing(0);
//    titleBarLayout->setMargin(0);

    imageLabel= new QLabel();
    imageLabel->setWindowOpacity(0.8);
    imageLabel->setStyleSheet("border-image:url(:images/yu.png);");
    imageLabel->setFixedHeight(this->height*0.11);
    imageLabel->setBackgroundRole(QPalette::Base);
    imageLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    imageLabel->setScaledContents(true);

    imageLabelLayout = new QGridLayout(imageLabel);
    imageLabelLayout->addWidget(cityOption, 0, 0);
    imageLabelLayout->addItem(controlAreaItem, 0, 1);
    imageLabelLayout->addWidget(searchingButton, 0, 2);
    imageLabelLayout->addItem(controlAreaItem, 1, 0);

    subjectsArea = new pmupSubjectsPage(this->width, int(this->height*0.24));

    advertisementArea = new AdvertisementArea(this->width, int(this->height*0.65));

    myLayout = new QVBoxLayout(this);
    myLayout->addWidget(imageLabel);
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
        cityOption->setIconSize(QSize(0,height));
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
