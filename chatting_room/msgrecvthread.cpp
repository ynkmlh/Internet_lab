#include "msgrecvthread.h"


MsgRecvThread::MsgRecvThread(SOCKET mSocket,QWidget *parent): QThread(parent)//需要包含QWidget
{
    this->socket = mSocket;
}

void MsgRecvThread::run(){
    sockaddr_in socket_addr;
    int client_addr_len = sizeof(socket_addr);
    new_socket = accept(socket,(sockaddr *)&socket_addr, &client_addr_len);
    if (SOCKET_ERROR == new_socket)
    {
        qDebug()<<"Accept Failed: "<<WSAGetLastError()<<endl;
        exit(1);
    }
    emit(isSocket(new_socket));
    myRecv(new_socket);//开始接收客户端的数据
}

void MsgRecvThread::myRecv(SOCKET new_socket){
    char buffer[2048];
    while(true){
        memset(buffer,0,sizeof(buffer));
        if (recv(new_socket, buffer, 2048, 0) < 0)
        {
//            qDebug()<<"Receive Data Failed!"<<endl;
            exit(1);
        }
        //将接收到的信息通过信号传出去
        this->mMsgRecv = QString(buffer);
        emit(isRecvMsg(this->mMsgRecv));//接收到数据就发出一个信号
    }
}//用于关联数据的接收
