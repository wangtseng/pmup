#ifndef ADVERTISEMENTAREA_H
#define ADVERTISEMENTAREA_H

#include <QFrame>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QTabWidget>
#include <QHBoxLayout>


/**
 * @brief The AdvertisementArea class
 */
class AdvertisementArea : public QFrame
{
    Q_OBJECT

private:
    int width;
    int height;

    QString tabWidgetStyleSheet;

    QLabel* xdInfomationBar;

    QVBoxLayout *myLayout;
    QHBoxLayout *xdInfomationBarLayout;

    QPushButton* xdInfomationLabel;
    QLineEdit *xdInfomationEdit;

    QWidget *xdPopularArea;
    QTabWidget *xdPopularOptions;
    QVBoxLayout *xdPopularAreaLayout;

public:
    explicit AdvertisementArea(int width, int height);
    void initVariable();
    void constructIHM();
    void setConnection();

signals:

public slots:
};

#endif // ADVERTISEMENTAREA_H
