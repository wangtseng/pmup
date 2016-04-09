#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QWidget>
#include <QScrollArea>
#include <QComboBox>
#include <QToolButton>
#include <QPushButton>
#include <QImage>
#include <QImageReader>
#include <QSpacerItem>

#include <QDebug>
#include "SearchingArea.h"
#include "pmupSubjectsPage.h"
#include "AdvertisementArea.h"



class pmupFirstPage : public QWidget
{
    Q_OBJECT

private:
    int width;
    int height;

    QVBoxLayout *myLayout;
    QHBoxLayout *titleBarLayout;

    QComboBox *cityOption;

    QLineEdit *serchingArea;

    QToolButton *searchingButton;
    QToolButton *scanQCodeButton;

    QSpacerItem *controlAreaItem;

    AdvertisementArea *advertisementArea;

    QLabel *titleBar;
    QLabel *imageLabel;
    QGridLayout *imageLabelLayout;

    pmupSubjectsPage *subjectsArea;
    QImage newImage;

public:
    void initVariable();
    void constructIHM();
    void drawBackground();
    void setConnections();
    void setSize(int width, int height);
    void fillCityOptions(QComboBox *cityOption, int width, int height);

public:
    explicit pmupFirstPage(QWidget *parent = 0);

signals:

public slots:
};

#endif // MAINPAGE_H
