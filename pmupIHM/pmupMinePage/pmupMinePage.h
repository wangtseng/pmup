#ifndef PMUPMINEPAGE_H
#define PMUPMINEPAGE_H

#include <QWidget>

class pmupMinePage : public QWidget
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
    explicit pmupMinePage(QWidget *parent = 0);

signals:

public slots:
};

#endif // PMUPMINEPAGE_H
