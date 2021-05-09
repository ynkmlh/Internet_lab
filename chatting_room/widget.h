#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<client.h>
#include<server.h>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

    void dealMsg(QString qmsg);
private:
    server* s;
    client* c;
    Ui::Widget *ui;
};

#endif // WIDGET_H
