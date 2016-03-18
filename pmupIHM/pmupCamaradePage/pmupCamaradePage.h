#ifndef PMUPCAMARADEPAGE_H
#define PMUPCAMARADEPAGE_H

#include <QWidget>

class pmupCamaradePage : public QWidget
{
    Q_OBJECT

private:
    int width;
    int height;

public:
    void setSize(int width, int height);

public:
    explicit pmupCamaradePage(QWidget *parent = 0);

signals:

public slots:
};

#endif // PMUPCAMARADEPAGE_H
