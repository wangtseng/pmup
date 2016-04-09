#include "AdvertisementArea.h"


/**
 * @brief AdvertisementArea::AdvertisementArea
 * @param width
 * @param height
 */
AdvertisementArea::AdvertisementArea(int width, int height) : QFrame()
{
    this->width = width;
    this->height = height;
    this->initVariable();
    this->constructIHM();
    this->setConnection();
}

//! -------------------------------------------------------------------------------------------
//!
//! \brief AdvertisementArea::initVariable
//!
void AdvertisementArea::initVariable(){
    this->setFixedSize(this->width, this->height);
    tabWidgetStyleSheet = "QTabWidget::tab-bar {alignment: left;}"
                          "QTabBar::tab { background: teal; color: aliceblue; padding: 0px; border-top: 0px solid gainsboro; border-bottom: 0px solid orange; height: "+QString::number(height*0.08)+"px; width: "+QString::number(width*0.25)+"px;  } "
                          "QTabBar::tab:selected {background: aliceblue; color: teal; padding: 0px; border-top: 1px solid teal; border-bottom: 1px solid teal;} "
                          "QTabWidget::pane { border: 0; }";
}

//! --------------------------------------------------------------------------------------------
//!
//! \brief AdvertisementArea::constructIHM
//!
void AdvertisementArea::constructIHM(){

    xdInfomationLabel = new QPushButton();
    xdInfomationLabel->setFixedSize(width*0.3, height*0.07);
    xdInfomationLabel->setIconSize(QSize(width*0.25, height*0.05));
    xdInfomationLabel->setIcon(QIcon(":/images/info.png"));

    xdInfomationEdit = new QLineEdit();
    xdInfomationEdit->setStyleSheet("QLineEdit {border: 1px solid teal;border-radius: 0px; "
                                    "background: white;selection-background-color: darkgray;}");
    xdInfomationEdit->setFixedSize(width*0.7, height*0.07);

    xdInfomationBar = new QLabel();
    xdInfomationBar->setFixedHeight(height*0.07);
    xdInfomationBarLayout = new QHBoxLayout(xdInfomationBar);
    xdInfomationBarLayout->addWidget(xdInfomationLabel);
    xdInfomationBarLayout->addWidget(xdInfomationEdit);
    xdInfomationBarLayout->setSpacing(0);
    xdInfomationBarLayout->setMargin(0);

    xdPopularOptions = new QTabWidget();
    xdPopularOptions->setTabPosition(QTabWidget::North);
    xdPopularOptions->setStyleSheet(tabWidgetStyleSheet);
    xdPopularOptions->setFixedSize(width, height*0.93);
    xdPopularOptions->insertTab(0, new QLabel, "优惠课程");
    xdPopularOptions->insertTab(1, new QLabel, "热门课程");
    xdPopularOptions->insertTab(2, new QLabel, "机构推荐");
    xdPopularOptions->insertTab(3, new QLabel, "最爱活动");

    xdPopularArea = new QWidget();
    xdPopularArea->setFixedHeight(height*0.93);
    xdPopularAreaLayout = new QVBoxLayout(xdPopularArea);
    xdPopularAreaLayout->addWidget(xdPopularOptions);
    xdPopularAreaLayout->setMargin(0);
    xdPopularAreaLayout->setSpacing(0);

    myLayout = new QVBoxLayout(this);
    myLayout->addWidget(xdInfomationBar);
    myLayout->addWidget(xdPopularArea);
    myLayout->setSpacing(2);
    myLayout->setMargin(0);
}

//! ----------------------------------------------------------------------------------------
//!
//! \brief AdvertisementArea::setConnection
//!
void AdvertisementArea::setConnection(){

}
