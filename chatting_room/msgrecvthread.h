#ifndef MSGRECVTHREAD_H
#define MSGRECVTHREAD_H

#include<winsock2.h>
#include<QObject>
#include<QThread>
#include<QWidget>
#include<QDebug>
class MsgRecvThread:public QThread//这个类用于开辟多线程进行循环监听
{
    Q_OBJECT
public:
    explicit MsgRecvThread(SOCKET mSocket,QWidget *parent = nullptr);
    void run();
    void myRecv(SOCKET new_socket);
private:
    SOCKET socket;//
    QString mMsgRecv;//保存接收的数据
    SOCKET new_socket;
signals:
    void isRecvMsg(QString msg);
    void isSocket(SOCKET newsocket);
public slots:
};

#endif // MSGRECVTHREAD_H
