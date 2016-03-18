#ifndef MODULEIPCONFIG_H
#define MODULEIPCONFIG_H

#include<QHostAddress>


typedef enum {
    PISS = 0,
    MISS,
    CCISS
}ModuleCode;


class ModuleIpConfig
{
public:
    ModuleIpConfig();

    QHostAddress getIpAddress();
    int getPort();
    QString getName();
    int getSocketrec();
    int getSockettrans();
    quint32 getClientlistenport();
    bool getCode();
    int getModuleNumber();

    void setIpAddress(QHostAddress Addr);
    void setPort(int Port);
    void setName(QString Name);
    void setSocketrec(int Socketrec);
    void setSockettrans(int Sockettrans);
    void setClientlistenport(quint32 Clientlistenport);
    void setCode(bool Code);
    void setModuleNumber(int moduleNumber);

private:
    int moduleNumber;
    QHostAddress addr;
    int port;
    QString name;
    qintptr socketrec;//���յ���socket
    qintptr sockettrans;//�������ӵ�socket
    quint32 clientlistenport;//�Է������Ķ˿ں�
    bool code;//��ʶ��
};

#endif // MODULEIPCONFIG_H
