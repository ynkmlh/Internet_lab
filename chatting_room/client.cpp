#include "client.h"

client::client(char* ip_addr)
{
    WORD socketVersion = MAKEWORD(2,2);//版本设置
    if(WSAStartup(socketVersion,&wsadata)!=0){
        qDebug()<<"Init error"<<endl;
        exit(1);
      }//初始化

    this->clientSocket = socket(AF_INET,SOCK_STREAM,0);
    if(SOCKET_ERROR==clientSocket){
      qDebug()<<"create socket error"<<endl;
      exit(1);
    }//创建socket


    socket_addr.sin_family = AF_INET;
//    this->ip_address = ui->input_ip->toPlainText().toUtf8().data();//将Qtextedit中获取的ip转换为char*
    this->ip_address = ip_addr;
    socket_addr.sin_addr.S_un.S_addr = inet_addr(ip_address);
    socket_addr.sin_port=htons(PORT);
    //以上步骤设置ip和端口号
    if (SOCKET_ERROR ==::connect(clientSocket, (LPSOCKADDR)&socket_addr, sizeof(socket_addr)))
    {
        qDebug()<<"Can Not Connect To Server IP!\n";
        exit(1);
    }//客户端调用connect函数进行连接
}
//客户端的构造函数传入服务端的ip地址进行构造

client::~client(){
    closesocket(clientSocket);
    //winsock 释放
    WSACleanup();
    if(mMsgClientRecvThread!=nullptr)
        mMsgClientRecvThread->quit();
}
