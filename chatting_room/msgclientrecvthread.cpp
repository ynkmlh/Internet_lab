#include "msgclientrecvthread.h"

msgClientRecvThread::msgClientRecvThread(SOCKET mSocket,QWidget *parent):QThread(parent)
{
    this->socket = mSocket;
}

void msgClientRecvThread::run(){
    char buffer[2048];
    while(true){
        memset(buffer,0,sizeof(buffer));
        if (recv(socket, buffer, 2048, 0) < 0)
        {
//            qDebug()<<"Receive Data Failed!"<<endl;
            exit(1);
        }
        //将接收到的信息通过信号传出去
        this->mMsgRecv = QString(buffer);
        emit(isRecvMsg(this->mMsgRecv));//接收到数据就发出一个信号
    }
}
