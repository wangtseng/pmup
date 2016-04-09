#include "pmupMainWindow.h"


//! -------------------------------------------------------------------
//!
//! \brief pmupMainWindow::pmupMainWindow
//! \param parent
//!
pmupMainWindow::pmupMainWindow(int appWidth, int appHeight) : QFrame(){

    setSize(appWidth, appHeight);

    initVariable();
    constructIHM();
    setConnections();
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
    globalBackgroundColor = "teal";
    globalFontColor = "aliceblue";
    bottomBorderColor = "red";

    tabWidgetStyleSheet = "QTabWidget::tab-bar {alignment: left;}"
                          "QTabBar::tab { background: teal; color: aliceblue; padding: 0px; border-top: 0px solid gainsboro; border-bottom: 0px solid orange; height: "+QString::number(appHeight*0.06)+"px; width: "+QString::number(appWidth*0.2)+"px;  } "
                          "QTabBar::tab:selected {background: aliceblue; color: teal; padding: 0px; border-top: 3px solid red; border-bottom: 0px solid orange;} "
                          "QTabWidget::pane { border: 0; }";
}

//! --------------------------------------------------------------------
//!
//! \brief pmupEnterPage::constructIHM
//!
void pmupMainWindow::constructIHM(){

    firstPage = new pmupFirstPage();
    firstPage->setSize(this->appWidth, this->appHeight*0.94);

    camaradePage = new pmupCamaradePage();
    camaradePage->setSize(this->appWidth, this->appHeight*0.94);

    nearPage = new pmupNearbyPage();
    nearPage->setSize(this->appWidth, this->appHeight*0.94);

    minePage = new pmupMinePage();
    minePage->setSize(this->appWidth, this->appHeight*0.94);

    mainPagesContainer = new QTabWidget();
    mainPagesContainer->setFont(QFont("Helvetica", 14, QFont::AnyStyle, false));
    mainPagesContainer->setTabPosition(QTabWidget::South);
    mainPagesContainer->setStyleSheet(tabWidgetStyleSheet);
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

//! ---------------------------------------------------------------------------------------------
//!
//! \brief pmupEnterPage::setConnections
//!
void pmupMainWindow::setConnections(){
    this->connect(mainPagesContainer, SIGNAL(currentChanged()), this, SLOT(on_TabOptionCLicked()));
}

//! ---------------------------------------------------------------------------------------------
//!
//! \brief pmupMainWindow::on_TabOptionCLicked
//!
void pmupMainWindow::on_TabOptionCLicked(){
    qDebug()<<"on_TabOptionCLicked"<<mainPagesContainer->currentIndex();
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
