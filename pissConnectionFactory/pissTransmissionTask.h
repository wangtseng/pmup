#ifndef PISSTRANSMISSIONTASK_H
#define PISSTRANSMISSIONTASK_H

#include <QThread>
#include <QObject>
#include <QTcpSocket>
#include <QTimer>
#include "pissNetworkEnvironment.h"
#include "OutputQueue.h"


class pissTransmissionTask : public QObject
{
    Q_OBJECT
private:
    QTcpSocket* socketTransmission;
    QVector <OutputQueue*> *oq;
    pissNetworkEnvironment *environment;
    QTimer *transmissionTimer;
    int frameCounter;
    QMutex outputMutex;
public:
    pissTransmissionTask(QVector <OutputQueue*> *oq, pissNetworkEnvironment* environment);
    ~pissTransmissionTask();
    void connectTo(int moduleNumber);
public slots:
    void startTransfer();
    void transfer();
};

#endif // PISSTRANSMISSIONTASK_H
