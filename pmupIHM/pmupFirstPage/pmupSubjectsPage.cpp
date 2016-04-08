#include "pmupSubjectsPage.h"

pmupSubjectsPage::pmupSubjectsPage(int width, int height) : QWidget()
{
    this->width = width;
    this->height = height;
    this->setFixedHeight(this->height);

    basicSubjectOption = new QPushButton();
    basicSubjectOption->setFixedSize(QSize(this->width*0.25, this->height*0.5));
    basicSubjectOption->setIconSize(QSize(this->width*0.22, this->height*0.4));
    basicSubjectOption->setIcon(QIcon(":/images/basicSubject.png"));
    basicSubjectOption->setFlat(true);
    //basicSubjectOption->setStyleSheet("QPushButton{background-color: beige; border:none;} ");

    languageOption = new QPushButton();
    languageOption->setFixedSize(QSize(this->width*0.25, this->height*0.5));
    languageOption->setIcon(QIcon(":/images/language.png"));
    languageOption->setIconSize(QSize(this->width*0.22, this->height*0.4));
    languageOption->setFlat(true);
    //languageOption->setStyleSheet("QPushButton{background-color: beige; border:none;} ");

    drivingOption = new QPushButton();
    drivingOption->setFixedSize(QSize(this->width*0.25, this->height*0.5));
    drivingOption->setIcon(QIcon(":/images/drive.png"));
    drivingOption->setIconSize(QSize(this->width*0.22, this->height*0.4));
    drivingOption->setFlat(true);
    //drivingOption->setStyleSheet("QPushButton{background-color: beige; border:none;} ");

    sportOption = new QPushButton();
    sportOption->setFixedSize(QSize(this->width*0.25, this->height*0.5));
    sportOption->setIcon(QIcon(":/images/sports.png"));
    sportOption->setIconSize(QSize(this->width*0.22, this->height*0.4));
    sportOption->setFlat(true);
    //sportOption->setStyleSheet("QPushButton{background-color: beige; border:none;} ");

    cookingOption = new QPushButton();
    cookingOption->setFixedSize(QSize(this->width*0.25, this->height*0.5));
    cookingOption->setIcon(QIcon(":/images/cooking.png"));
    cookingOption->setIconSize(QSize(this->width*0.22, this->height*0.4));
    cookingOption->setFlat(true);
    //cookingOption->setStyleSheet("QPushButton{background-color: beige; border:none;} ");

    musicOption = new QPushButton();
    musicOption->setFixedSize(QSize(this->width*0.25, this->height*0.5));
    musicOption->setIcon(QIcon(":/images/music.png"));
    musicOption->setIconSize(QSize(this->width*0.22, this->height*0.4));
    musicOption->setFlat(true);
    //musicOption->setStyleSheet("QPushButton{background-color: beige; border:none;} ");

    aboardOption = new QPushButton();
    aboardOption->setFixedSize(QSize(this->width*0.25, this->height*0.5));
    aboardOption->setIcon(QIcon(":/images/aboard.png"));
    aboardOption->setIconSize(QSize(this->width*0.22, this->height*0.4));
    aboardOption->setFlat(true);
    //aboardOption->setStyleSheet("QPushButton{background-color: beige; border:none;} ");

    dancingOption = new QPushButton();
    dancingOption->setFixedSize(QSize(this->width*0.25, this->height*0.5));
    dancingOption->setIcon(QIcon(":/images/dancing.png"));
    dancingOption->setIconSize(QSize(this->width*0.22, this->height*0.4));
    dancingOption->setFlat(true);
    //dancingOption->setStyleSheet("QPushButton{background-color: beige; border:none;} ");

    subjectsAreaWidget = new QWidget();
    subjectsAreaWidget->setStyleSheet("background-color:beige; border: 0px solid lightgray;");

    subjectsAreaLayout = new QGridLayout(subjectsAreaWidget);
    subjectsAreaLayout->addWidget(basicSubjectOption, 0, 0);
    subjectsAreaLayout->addWidget(languageOption, 0, 1);
    subjectsAreaLayout->addWidget(drivingOption, 0, 2);
    subjectsAreaLayout->addWidget(aboardOption, 0, 3);
    subjectsAreaLayout->addWidget(sportOption, 1, 0);
    subjectsAreaLayout->addWidget(cookingOption, 1, 1);
    subjectsAreaLayout->addWidget(musicOption, 1, 2);
    subjectsAreaLayout->addWidget(dancingOption, 1, 3);
    subjectsAreaLayout->setSpacing(0);
    subjectsAreaLayout->setMargin(0);

    subjectsPageLayout = new QVBoxLayout(this);
    subjectsPageLayout->addWidget(subjectsAreaWidget);
    subjectsPageLayout->setSpacing(0);
    subjectsPageLayout->setMargin(0);
}
