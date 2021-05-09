#ifndef MSGCLIENTRECVTHREAD_H
#define MSGCLIENTRECVTHREAD_H

#include<winsock2.h>
#include<QObject>
#include<QThread>
#include<QWidget>
#include<QDebug>
class msgClientRecvThread:public QThread//这个类用于客户端的监听
{
    Q_OBJECT
public:
   explicit msgClientRecvThread(SOCKET mSocket,QWidget *parent = nullptr);
    void run();
private:
    SOCKET socket;//
    QString mMsgRecv;//保存接收的数据
signals:
    void isRecvMsg(QString msg);
public slots:
};

#endif // MSGCLIENTRECVTHREAD_H
