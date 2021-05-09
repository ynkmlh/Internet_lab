#ifndef SERVER_H
#define SERVER_H

#include<winsock2.h>
#include<QDebug>
#include<msgrecvthread.h>
class server
{
public:
    server();
    ~server();
    MsgRecvThread* mMsgRecvThread;
    SOCKET serverSocket;
    SOCKET newSocket;
private:

    sockaddr_in socket_addr;
    WSADATA wsadata;
    unsigned short PORT = 10086;
    const char* ip_address;
};

#endif // SERVER_H
