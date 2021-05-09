#ifndef CLIENT_H
#define CLIENT_H

#include<winsock2.h>
#include<QDebug>
#include<msgrecvthread.h>
#include<QWidget>
#include<msgclientrecvthread.h>
class client
{
public:
    client(char* ip_addr);
    ~client();
    msgClientRecvThread* mMsgClientRecvThread;
    SOCKET clientSocket;
private:
    sockaddr_in socket_addr;
    const char* ip_address;
    WSADATA wsadata;
    unsigned short PORT = 10086;

};

#endif // CLIENT_H
