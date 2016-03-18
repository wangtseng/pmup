#include "pmupSubjectsPage.h"

pmupSubjectsPage::pmupSubjectsPage(int width, int height) : QWidget()
{
    this->setStyleSheet("background-color:beige");
    this->width = width;
    this->height = height;
    this->setFixedHeight(this->height);

    textAdvertisementLabel = new QLabel();
    textAdvertisementLabel->setFixedHeight(this->height*0.15);

    subjectPagesIndicationArea = new QLabel();
    subjectPagesIndicationArea->setFixedHeight(this->height*0.05);

    basicSubjectOption = new QPushButton();
    basicSubjectOption->setFixedSize(QSize(this->width*0.33, this->height*0.4));
    basicSubjectOption->setIconSize(QSize(this->width*0.20, this->height*0.3));
    basicSubjectOption->setIcon(QIcon(":/images/basicSubject.png"));
    basicSubjectOption->setFlat(true);

    languageOption = new QPushButton();
    languageOption->setFixedSize(QSize(this->width*0.33, this->height*0.4));
    languageOption->setIcon(QIcon(":/images/language.png"));
    languageOption->setIconSize(QSize(this->width*0.20, this->height*0.3));
    languageOption->setFlat(true);

    drivingOption = new QPushButton();
    drivingOption->setFixedSize(QSize(this->width*0.33, this->height*0.4));
    drivingOption->setIcon(QIcon(":/images/drive.png"));
    drivingOption->setIconSize(QSize(this->width*0.20, this->height*0.3));
    drivingOption->setFlat(true);

    sportOption = new QPushButton();
    sportOption->setFixedSize(QSize(this->width*0.33, this->height*0.4));
    sportOption->setIcon(QIcon(":/images/sports.png"));
    sportOption->setIconSize(QSize(this->width*0.20, this->height*0.3));
    sportOption->setFlat(true);

    cookingOption = new QPushButton();
    cookingOption->setFixedSize(QSize(this->width*0.33, this->height*0.4));
    cookingOption->setIcon(QIcon(":/images/cooking.png"));
    cookingOption->setIconSize(QSize(this->width*0.20, this->height*0.3));
    cookingOption->setFlat(true);

    musicOption = new QPushButton();
    musicOption->setFixedSize(QSize(this->width*0.33, this->height*0.4));
    musicOption->setIcon(QIcon(":/images/music.png"));
    musicOption->setIconSize(QSize(this->width*0.20, this->height*0.3));
    musicOption->setFlat(true);

    subjectsAreaWidget = new QWidget();
    subjectsAreaWidget->setStyleSheet("background-color:aliceBlue; border: 0px solid gaisboro;");

    subjectsAreaLayout = new QGridLayout(subjectsAreaWidget);
    subjectsAreaLayout->addWidget(basicSubjectOption, 0, 0);
    subjectsAreaLayout->addWidget(languageOption, 0, 1);
    subjectsAreaLayout->addWidget(drivingOption, 0, 2);
    subjectsAreaLayout->addWidget(sportOption, 1, 0);
    subjectsAreaLayout->addWidget(cookingOption, 1, 1);
    subjectsAreaLayout->addWidget(musicOption, 1, 2);
    subjectsAreaLayout->setSpacing(0);
    subjectsAreaLayout->setMargin(0);

    subjectsPageLayout = new QVBoxLayout(this);
    subjectsPageLayout->addWidget(textAdvertisementLabel);
    subjectsPageLayout->addWidget(subjectsAreaWidget);
    subjectsPageLayout->addWidget(subjectPagesIndicationArea);
    subjectsPageLayout->setSpacing(0);
    subjectsPageLayout->setMargin(0);
}

