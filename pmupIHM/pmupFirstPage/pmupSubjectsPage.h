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
    QLabel *subjectPagesIndicationArea;

    QWidget *subjectsAreaWidget;
    QGridLayout *subjectsAreaLayout;
    QPushButton *basicSubjectOption;
    QPushButton *languageOption;
    QPushButton *drivingOption;
    QPushButton *sportOption;
    QPushButton *cookingOption;
    QPushButton *musicOption;
    QPushButton *aboardOption;
    QPushButton *dancingOption;

    int width;
    int height;

public:
    explicit pmupSubjectsPage(int width, int height);

signals:

public slots:
};

#endif // PMUPSUBJECTSPAGE_H
