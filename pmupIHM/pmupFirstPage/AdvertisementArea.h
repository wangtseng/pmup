#ifndef ADVERTISEMENTAREA_H
#define ADVERTISEMENTAREA_H

#include <QFrame>

class AdvertisementArea : public QFrame
{
    Q_OBJECT

private:
    int width;
    int height;

public:
    explicit AdvertisementArea(int width, int height);
    void initVariable();
    void constructIHM();
    void setConnection();

signals:

public slots:
};

#endif // ADVERTISEMENTAREA_H
