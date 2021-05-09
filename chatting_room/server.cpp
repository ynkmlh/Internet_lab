#include "server.h"

server::server()
{
    WORD socketVersion = MAKEWORD(2,2);//版本设置
    if(WSAStartup(socketVersion,&wsadata)!=0){
        qDebug()<<"Init error"<<endl;
        exit(1);
      }//初始化
   this->serverSocket = socket(AF_INET,SOCK_STREAM,0);
       if(SOCKET_ERROR==serverSocket){
           qDebug()<<"create socket error"<<endl;
           exit(1);
       }//创建socket
       socket_addr.sin_family = AF_INET;
       //this->ip_address = ui->input_ip->toPlainText().toUtf8().data();//将Qtextedit中获取的ip转换为char*

       this->ip_address = "127.0.0.1";
       //暂时把ip地址写死，服务器的ip就是本机的地址
       socket_addr.sin_addr.S_un.S_addr = inet_addr(ip_address);
       socket_addr.sin_port=htons(PORT);
       //以上处理ip和端口号
       if (SOCKET_ERROR == bind(serverSocket, (LPSOCKADDR)&socket_addr, sizeof(socket_addr)))
       {
           qDebug()<<"unable to connect to this ip"<<endl;
           exit(1);
       }//服务端使用bind函数
       if (SOCKET_ERROR == listen(serverSocket, 10))
       {
           qDebug()<<"listening failed"<<endl;
           exit(1);
       }//服务端进行bind并监听
}
//在构造函数中进行服务器的socket的建立和设置listen监听

server::~server(){
    closesocket(serverSocket);
    //winsock 释放
    WSACleanup();
    if(mMsgRecvThread!=nullptr)
        mMsgRecvThread->quit();
}
