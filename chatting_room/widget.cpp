#include "widget.h"
#include "ui_widget.h"

#include <QDateTime>
#include<QDebug>
#include <QFileDiaLog>
#include <qshortcut.h>
#include<msgrecvthread.h>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //关键必须要注册否则不可以作为信号传递
    qRegisterMetaType<SOCKET>("SOCKET");
    setWindowTitle("chat room");//设置标题
    setFixedSize(722,408);//设置窗口大小不可变
    //开始从消息框中获取信息
    ui->receive_message->setReadOnly(true);//设置接收消息的文本框只读
//     发送功能
    connect(ui->send,&QPushButton::clicked,this,[=]{
        QString typein = ui->send_message->toPlainText();
        this->ui->send_message->setText("");//获取字符串并清空
        this->ui->receive_message->append("本地用户:");
        this->ui->receive_message->append(typein);//打印到发送区
        if(!(this->ui->listen->isEnabled())){//监听按键没有被启动
            if(send(this->s->newSocket, typein.toUtf8().data(), typein.length(), 0) < 0)
            {
                qDebug()<<"传输信息错误！"<<endl;
                exit(1);
            }
        }//如果监听按钮不可选，则是服务端
        else{
            if(send(this->c->clientSocket, typein.toUtf8().data(), typein.length(), 0) < 0)
            {
                qDebug()<<"传输信息错误！"<<endl;
                exit(1);
            }
        }//否则是客户端

    });

    connect(ui->connect,&QPushButton::clicked,this,[=]{
        QByteArray qba =  ui->input_ip->toPlainText().toLatin1();
        char* ip_addr =qba.data();//将Qtextedit中获取的ip转换为char*
        this->c = new client(ip_addr);
        ui->label->setText("客户端连接成功");

        //开启属于客户端的新的线程用于接收来自服务端的信息
        this->c->mMsgClientRecvThread = new msgClientRecvThread(this->c->clientSocket);
        this->c->mMsgClientRecvThread->start();
        connect(this->c->mMsgClientRecvThread,&msgClientRecvThread::isRecvMsg,this,&Widget::dealMsg);//通过connect将接收到的数据显示出来

    });//客户端进行连接
    connect(ui->listen,&QPushButton::clicked,this,[=]{
        this->s = new server();
        ui->listen->setEnabled(false);
        ui->label->setText("服务端启动成功");
        //只能启动服务器一次

        //因为ui进程不能被阻塞，所以考虑多线程，开辟一个新的线程用于监听客户端的请求;
        this->s->mMsgRecvThread = new MsgRecvThread(this->s->serverSocket);
        this->s->mMsgRecvThread->start();

        //接收new socket----位置很重要
        connect(this->s->mMsgRecvThread,&MsgRecvThread::isSocket,this,[this](SOCKET nsocket){
            this->s->newSocket = nsocket;
        });
        //通过connect将服务端接收到的数据发送到显示区域
        connect(this->s->mMsgRecvThread,&MsgRecvThread::isRecvMsg,this,&Widget::dealMsg);


    });//进行监听
    connect(ui->save,&QPushButton::clicked,this,[=]{
        QString location = QFileDialog::getOpenFileName(this,"保存于","C:\\Users\\skyfu\\Desktop\\");//保存的txt文件路径
        QFile *file = new QFile(location);//此路径下没有就会自己创建一个
        file->open(QIODevice::Append);//追加写入
        QString record = ui->receive_message->toPlainText();
        QTextStream txtOutput(file);

        QDateTime current_date_time =QDateTime::currentDateTime();
        QString current_date =current_date_time.toString("yyyy.MM.dd hh:mm:ss.zzz ddd");
        //获取当前时间
        txtOutput <<current_date<<endl;
        txtOutput <<record<<"\n";
        file->close();
    });//将记录保存


}
void Widget::dealMsg(QString qmsg){
    //将接受的数据打印到接收框内
    ui->receive_message->append("对方:");
    ui->receive_message->append(qmsg);
}//处理传递过来的msg


Widget::~Widget()
{
    delete ui;
}
