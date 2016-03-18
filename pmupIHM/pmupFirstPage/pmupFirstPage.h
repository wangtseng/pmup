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
#include <QDebug>
#include "SearchingArea.h"
#include "pmupSubjectsPage.h"


class pmupFirstPage : public QWidget
{
    Q_OBJECT

private:
    int width;
    int height;

    QVBoxLayout *myLayout;
    QHBoxLayout *titleBarLayout;
    QHBoxLayout *popularWidgetLayout;

    QComboBox *cityOption;

    QLineEdit *serchingArea;

    QToolButton *searchingButton;
    QToolButton *scanQCodeButton;

    QWidget *popularWidget;
    QWidget *advertisementArea;

    QLabel *titleBar;
    QLabel *rankingLabel;

    pmupSubjectsPage *subjectsArea;

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