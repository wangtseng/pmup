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
}

//! --------------------------------------------------------------------
//!
//! \brief pmupEnterPage::constructIHM
//!
void pmupMainWindow::constructIHM(){

    firstPage = new pmupFirstPage();
    firstPage->setSize(this->appWidth, this->appHeight*0.9);

    camaradePage = new pmupCamaradePage();
    camaradePage->setSize(this->appWidth, this->appHeight*0.9);

    nearPage = new pmupNearbyPage();
    nearPage->setSize(this->appWidth, this->appHeight*0.9);

    minePage = new pmupMinePage();
    minePage->setSize(this->appWidth, this->appHeight*0.9);

    mainPagesContainer = new QWidget();
    mainPagesContainer->setFixedHeight(this->appHeight*0.9);
    mainPagesContainerLayout = new QGridLayout(mainPagesContainer);
    mainPagesContainerLayout->addWidget(firstPage, 0, 0);
    mainPagesContainerLayout->addWidget(camaradePage, 0, 1);
    mainPagesContainerLayout->addWidget(nearPage, 1, 0);
    mainPagesContainerLayout->addWidget(minePage, 1, 1);
    mainPagesContainerLayout->setMargin(0);
    camaradePage->close();
    minePage->close();
    nearPage->close();
    camaradePage->setFixedSize(0,0);
    minePage->setFixedSize(0,0);
    nearPage->setFixedSize(0,0);


    //!---------------------------------------------------------------------------------------
    optionButtonsContainer = new QLabel();
    optionButtonsContainerLayout = new QHBoxLayout(optionButtonsContainer);

    firstPageOption = new QPushButton("课程");
    firstPageOption->setFixedSize(QSize(appWidth*0.15, appHeight*0.07));
    firstPageOption->setFlat(true);
    firstPageOption->setFont(QFont("Segoe UI",13, QFont::AnyStyle, true));

    camaradePageOption = new QPushButton("学友");
    camaradePageOption->setFixedSize(QSize(appWidth*0.15, appHeight*0.07));
    camaradePageOption->setFlat(true);
    camaradePageOption->setFont(QFont("Segoe UI",13, QFont::AnyStyle, true));

    nearPageOption = new QPushButton("附近");
    nearPageOption->setFixedSize(QSize(appWidth*0.15, appHeight*0.07));
    nearPageOption->setFlat(true);
    nearPageOption->setFont(QFont("Segoe UI",13, QFont::AnyStyle, true));

    minePageOption = new QPushButton("我的");
    minePageOption->setFixedSize(QSize(appWidth*0.15, appHeight*0.07));
    minePageOption->setFlat(true);
    minePageOption->setFont(QFont("Segoe UI",13, QFont::AnyStyle, true));

    indicationLabel = new QLabel();
    indicationLabel->setFixedSize(QSize(appWidth*0.4, appHeight*0.1));
    indicationLabel->setStyleSheet("background-color:aliceBlue");

    optionButtonsContainerLayout->addWidget(firstPageOption);
    optionButtonsContainerLayout->addWidget(camaradePageOption);
    optionButtonsContainerLayout->addWidget(nearPageOption);
    optionButtonsContainerLayout->addWidget(minePageOption);
    optionButtonsContainerLayout->addWidget(indicationLabel);
    optionButtonsContainerLayout->setMargin(0);
    optionButtonsContainerLayout->setSpacing(0);

    myLayout = new QVBoxLayout(this);
    myLayout->addWidget(mainPagesContainer);
    myLayout->addWidget(optionButtonsContainer);

    myLayout->setSpacing(0);
    myLayout->setMargin(0);

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
    this->connect(firstPageOption,    SIGNAL(clicked()),this, SLOT(onFirstPageOptionClicked()));
    this->connect(camaradePageOption, SIGNAL(clicked()),this, SLOT(onCamaradePageOptionClicked()));
    this->connect(nearPageOption,     SIGNAL(clicked()),this, SLOT(onNearPageOptionClicked()));
    this->connect(minePageOption,     SIGNAL(clicked()),this, SLOT(onMinePageOptionClicked()));
}

void pmupMainWindow::onFirstPageOptionClicked(){
    qDebug()<<"onFirstPageOptionClicked";
    firstPage->show();
    camaradePage->close();
    minePage->close();
    nearPage->close();
    firstPage->setFixedSize(appWidth,appHeight*0.9);
    camaradePage->setFixedSize(0,0);
    minePage->setFixedSize(0,0);
    nearPage->setFixedSize(0,0);

    firstPageOption->setStyleSheet( "border: 0px solid orange;"
                                    "background-color:"+this->globalFontColor +
                                    ";color:" + this->globalBackgroundColor );

    camaradePageOption->setStyleSheet("border: 0px solid orange;"
                                      "background-color:"+this->globalBackgroundColor +
                                       ";color:" + this->globalFontColor );

    nearPageOption->setStyleSheet("border: 0px solid orange;"
                                  "background-color:"+this->globalBackgroundColor +
                                  ";color:" + this->globalFontColor );

    minePageOption->setStyleSheet("border: 0px solid orange;"
                                  "background-color:"+this->globalBackgroundColor +
                                  ";color:" + this->globalFontColor );


    //this->setStyleSheet("background-color:" + globalBackgroundColor);

}

void pmupMainWindow::onCamaradePageOptionClicked(){
    qDebug()<<"onCamaradePageOptionClicked";
    firstPage->close();
    camaradePage->show();
    minePage->close();
    nearPage->close();
    firstPage->setFixedSize(0,0);
    camaradePage->setFixedSize(appWidth,appHeight*0.9);
    minePage->setFixedSize(0,0);
    nearPage->setFixedSize(0,0);

    firstPageOption->setStyleSheet("border: 0px solid orange;"
                                   "background-color:"+this->globalBackgroundColor +
                                   ";color:" + this->globalFontColor );

    camaradePageOption->setStyleSheet("border: 0px solid orange;"
                                      "background-color:"+this->globalFontColor +
                                      ";color:" + this->globalBackgroundColor );

    nearPageOption->setStyleSheet( "border: 0px solid orange;"
                                   "background-color:"+this->globalBackgroundColor +
                                   ";color:" + this->globalFontColor );

    minePageOption->setStyleSheet( "border: 0px solid orange;"
                                   "background-color:"+this->globalBackgroundColor +
                                   ";color:" + this->globalFontColor );


    //this->setStyleSheet("background-color:" + globalBackgroundColor);
}

void pmupMainWindow::onNearPageOptionClicked(){
    qDebug()<<"onNearPageOptionClicked";
    firstPage->close();
    camaradePage->close();
    minePage->close();
    nearPage->show();
    firstPage->setFixedSize(0,0);
    camaradePage->setFixedSize(0,0);
    minePage->setFixedSize(0,0);
    nearPage->setFixedSize(appWidth,appHeight*0.9);

    firstPageOption->setStyleSheet("border: 0px solid orange;"
                                   "background-color:"+this->globalBackgroundColor +
                                   ";color:" + this->globalFontColor );

    camaradePageOption->setStyleSheet( "border: 0px solid orange;"
                                       "background-color:"+this->globalBackgroundColor +
                                   ";color:" + this->globalFontColor );

    nearPageOption->setStyleSheet("border: 0px solid orange;"
                                  "background-color:"+this->globalFontColor +
                                      ";color:" + this->globalBackgroundColor );

    minePageOption->setStyleSheet( "border: 0px solid orange;"
                                   "background-color:"+this->globalBackgroundColor +
                                   ";color:" + this->globalFontColor );


    //this->setStyleSheet("background-color:" + globalBackgroundColor);

}

void pmupMainWindow::onMinePageOptionClicked(){
    qDebug()<<"onMinePageOptionClicked";
    firstPage->close();
    camaradePage->close();
    minePage->show();
    nearPage->close();
    firstPage->setFixedSize(0,0);
    camaradePage->setFixedSize(0,0);
    minePage->setFixedSize(appWidth,appHeight*0.9);
    nearPage->setFixedSize(0,0);

    firstPageOption->setStyleSheet("border: 0px solid orange;"
                                   "background-color:"+this->globalBackgroundColor +
                                   ";color:" + this->globalFontColor );

    camaradePageOption->setStyleSheet( "border: 0px solid orange;"
                                       "background-color:"+this->globalBackgroundColor +
                                   ";color:" + this->globalFontColor );

    nearPageOption->setStyleSheet( "border: 0px solid orange;"
                                   "background-color:"+this->globalBackgroundColor +
                                   ";color:" + this->globalFontColor );

    minePageOption->setStyleSheet("border: 0px solid orange;"
                                  "background-color:"+this->globalFontColor +
                                      ";color:" + this->globalBackgroundColor );

    //this->setStyleSheet("background-color:" + globalBackgroundColor);
}
