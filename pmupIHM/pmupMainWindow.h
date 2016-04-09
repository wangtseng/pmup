#ifndef PMUPENTERPAGE_H
#define PMUPENTERPAGE_H

#include <QWidget>
#include <QFrame>
#include <QPixmap>
#include <QBrush>
#include <QBitmap>
#include <QLabel>
#include <QApplication>
#include <QScreen>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QTabWidget>
#include <QPushButton>
#include <QString>
#include <QDebug>
#include <QTabWidget>

#include "pmupFirstPage.h"
#include "pmupCamaradePage.h"
#include "pmupMinePage.h"
#include "pmupNearbyPage.h"



/**
 * @brief The pmupMainWindow class
 */
class pmupMainWindow : public QFrame
{
    Q_OBJECT

private:
    int appWidth;
    int appHeight;

    QString globalBackgroundColor;
    QString globalFontColor;
    QString bottomBorderColor;
    QString tabWidgetStyleSheet;

    QPixmap *pixmap;
    QScreen *screen;

    pmupFirstPage* firstPage;
    pmupCamaradePage* camaradePage;
    pmupMinePage* minePage;
    pmupNearbyPage* nearPage;

    QTabWidget *mainPagesContainer;

    QVBoxLayout *myLayout;

public:
    void initVariable();
    void constructIHM();
    void drawBackground();
    void setConnections();
    void setSize(int appWidth, int appHeight);
    void onFirstPageOptionClicked();
    void onCamaradePageOptionClicked();
    void onNearPageOptionClicked();
    void onMinePageOptionClicked();

public slots:
    void on_TabOptionCLicked();

public:
    pmupMainWindow(int appWidth, int appHeight);
    ~pmupMainWindow();
};

#endif // PMUPENTERPAGE_H
