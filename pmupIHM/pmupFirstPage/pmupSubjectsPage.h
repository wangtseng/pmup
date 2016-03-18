#ifndef PMUPSUBJECTSPAGE_H
#define PMUPSUBJECTSPAGE_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QGridLayout>
#include <QPushButton>


class pmupSubjectsPage : public QWidget
{
    Q_OBJECT

private:
    QVBoxLayout *subjectsPageLayout;
    QLabel *textAdvertisementLabel;
    QLabel *subjectPagesIndicationArea;

    QWidget *subjectsAreaWidget;
    QGridLayout *subjectsAreaLayout;
    QPushButton *basicSubjectOption;
    QPushButton *languageOption;
    QPushButton *drivingOption;
    QPushButton *sportOption;
    QPushButton *cookingOption;
    QPushButton *musicOption;

    int width;
    int height;

public:
    explicit pmupSubjectsPage(int width, int height);

signals:

public slots:
};

#endif // PMUPSUBJECTSPAGE_H
