#include "pmupMainWindow.h"


//! -------------------------------------------------------------------
//!
//! \brief pmupMainWindow::pmupMainWindow
//! \param parent
//!
pmupMainWindow::pmupMainWindow(int appWidth, int appHeight) : QFrame()
{

    setSize(appWidth, appHeight);

    initVariable();
    constructIHM();
    setConnections();
    onFirstPageOptionClicked();

    //this->drawBackground();
}

//! -------------------------------------------------------------------
//!
//! \brief destructeur pmupEnterPage::~pmupEnterPage
//!
pmupMainWindow::~pmupMainWindow(){

}

//! -------------------------------------------------------------------
//!
//! \brief pmupEnterPage::setSize
//! \param appWidth
//! \param appHeight
//!
void pmupMainWindow::setSize(int appWidth, int appHeight){
    this->appWidth = appWidth;
    this->appHeight = appHeight;
}

//! --------------------------------------------------------------------
//!
//! \brief pmupEnterPage::initVariable
//!
void pmupMainWindow::initVariable(){
    globalBackgroundColor = "mediumspringgreen";
    globalFontColor = "beige";
    bottomBorderColor = "red";

    the_tab_style =   "QTabWidget::tab-bar {alignment: left;}"
                      "QTabBar::tab { background: mediumspringgreen; color: beige; padding: 0px; border-top: 0px solid gainsboro; border-bottom: 0px solid orange; height: "+QString::number(appHeight*0.05)+"px; width: "+QString::number(appWidth*0.15)+"px;  } "
                      "QTabBar::tab:selected {background: beige; color: mediumspringgreen; padding: 0px; border-top: 0px solid gainsboro; border-bottom: 0px solid orange;} "
                      "QTabWidget::pane { border: 0; }";
}

//! --------------------------------------------------------------------
//!
//! \brief pmupEnterPage::constructIHM
//!
void pmupMainWindow::constructIHM(){

    firstPage = new pmupFirstPage();
    firstPage->setSize(this->appWidth, this->appHeight*0.95);

    camaradePage = new pmupCamaradePage();
    camaradePage->setSize(this->appWidth, this->appHeight*0.95);

    nearPage = new pmupNearbyPage();
    nearPage->setSize(this->appWidth, this->appHeight*0.95);

    minePage = new pmupMinePage();
    minePage->setSize(this->appWidth, this->appHeight*0.95);

    mainPagesContainer = new QTabWidget();
    mainPagesContainer->setTabPosition(QTabWidget::South);
    mainPagesContainer->setStyleSheet(the_tab_style);
    mainPagesContainer->setFixedHeight(this->appHeight);
    mainPagesContainer->insertTab(0, firstPage, "课程");
    mainPagesContainer->insertTab(1, camaradePage, "学友");
    mainPagesContainer->insertTab(2, nearPage, "附近");
    mainPagesContainer->insertTab(3, minePage, "我的");

    myLayout = new QVBoxLayout(this); 
    myLayout->addWidget(mainPagesContainer);
    myLayout->setSpacing(2);
    myLayout->setMargin(2);
}

//! --------------------------------------------------------------------
//!
//! \brief pmupEnterPage::drawBackground
//!
void pmupMainWindow::drawBackground(){
    pixmap = new QPixmap(":/images/background.png");
    QPalette p =  this->palette();

    p.setBrush(QPalette::Background,
               QBrush(pixmap->scaled(QSize(this->appWidth, this->appHeight),
                                     Qt::IgnoreAspectRatio,
                                     Qt::SmoothTransformation)));

    this->setPalette(p);
    this->setMask(pixmap->mask());
}

//! --------------------------------------------------------------------
//!
//! \brief pmupEnterPage::setConnections
//!
void pmupMainWindow::setConnections(){

}

//! ---------------------------------------------------------------------------------------------
//!
//! \brief pmupMainWindow::onFirstPageOptionClicked
//!
void pmupMainWindow::onFirstPageOptionClicked(){

}

//! ---------------------------------------------------------------------------------------------
//!
//! \brief pmupMainWindow::onCamaradePageOptionClicked
//!
void pmupMainWindow::onCamaradePageOptionClicked(){

}

//! ---------------------------------------------------------------------------------------------
//!
//! \brief pmupMainWindow::onNearPageOptionClicked
//!
void pmupMainWindow::onNearPageOptionClicked(){

}

//! ---------------------------------------------------------------------------------------------
//!
//! \brief pmupMainWindow::onMinePageOptionClicked
//!
void pmupMainWindow::onMinePageOptionClicked(){

}
