#ifndef PMUPNEARBYPAGE_H
#define PMUPNEARBYPAGE_H

#include <QWidget>

class pmupNearbyPage : public QWidget
{
    Q_OBJECT

private:
    int width;
    int height;

public:
    void setSize(int width, int height);
    void init();
    void construct();
    void setConnection();

public:
    explicit pmupNearbyPage(QWidget *parent = 0);

signals:

public slots:
};

#endif // PMUPNEARBYPAGE_H
