#ifndef SEARCHINGAREA_H
#define SEARCHINGAREA_H

#include <QWidget>
#include <QLineEdit>
#include <QVBoxLayout>

class SearchingArea : public QWidget
{
    Q_OBJECT

private:
    QVBoxLayout *searchingAreaLayout;
    QLineEdit *searchingEdit;

    int appWidth;
    int appHeight;

public:
    void initVariable();
    void constructIHM();
    void drawBackground();
    void setConnections();
    void setSize(int appWidth, int appHeight);

public:
    explicit SearchingArea(QWidget *parent = 0);

signals:

public slots:
};

#endif // SEARCHINGAREA_H
