/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QTextEdit *receive_message;
    QTextEdit *send_message;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_2;
    QPushButton *listen;
    QSpacerItem *verticalSpacer;
    QPushButton *send;
    QSpacerItem *verticalSpacer_3;
    QPushButton *save;
    QSpacerItem *verticalSpacer_4;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QTextEdit *input_ip;
    QPushButton *connect;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(722, 408);
        Widget->setMinimumSize(QSize(0, 0));
        Widget->setMaximumSize(QSize(16777215, 16777215));
        verticalLayoutWidget = new QWidget(Widget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 20, 401, 321));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        receive_message = new QTextEdit(verticalLayoutWidget);
        receive_message->setObjectName(QString::fromUtf8("receive_message"));
        receive_message->setMaximumSize(QSize(400, 150));

        verticalLayout->addWidget(receive_message);

        send_message = new QTextEdit(verticalLayoutWidget);
        send_message->setObjectName(QString::fromUtf8("send_message"));
        send_message->setMaximumSize(QSize(400, 75));

        verticalLayout->addWidget(send_message);

        widget = new QWidget(Widget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(430, 170, 231, 161));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        listen = new QPushButton(widget);
        listen->setObjectName(QString::fromUtf8("listen"));

        verticalLayout_2->addWidget(listen);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        send = new QPushButton(widget);
        send->setObjectName(QString::fromUtf8("send"));

        verticalLayout_2->addWidget(send);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        save = new QPushButton(widget);
        save->setObjectName(QString::fromUtf8("save"));

        verticalLayout_2->addWidget(save);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_4);

        widget_2 = new QWidget(Widget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(430, 50, 231, 111));
        verticalLayout_3 = new QVBoxLayout(widget_2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label = new QLabel(widget_2);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_3->addWidget(label);

        input_ip = new QTextEdit(widget_2);
        input_ip->setObjectName(QString::fromUtf8("input_ip"));

        verticalLayout_3->addWidget(input_ip);

        connect = new QPushButton(widget_2);
        connect->setObjectName(QString::fromUtf8("connect"));

        verticalLayout_3->addWidget(connect);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        listen->setText(QCoreApplication::translate("Widget", "\344\276\246\345\220\254", nullptr));
        send->setText(QCoreApplication::translate("Widget", "\345\217\221\351\200\201", nullptr));
        save->setText(QCoreApplication::translate("Widget", "\344\277\235\345\255\230\350\256\260\345\275\225", nullptr));
        label->setText(QCoreApplication::translate("Widget", "\347\233\256\346\240\207", nullptr));
        connect->setText(QCoreApplication::translate("Widget", "\350\277\236\346\216\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
