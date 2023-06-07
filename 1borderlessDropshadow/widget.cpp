#include "widget.h"
#include "ui_widget.h"
#include "QMouseEvent"
#include "QGraphicsDropShadowEffect"

Widget::Widget(QWidget *parent) :QWidget(parent), ui(new Ui::Widget)
{                                         //父类QWidget的constructor   子类Widget的初始化列表
    ui->setupUi(this);

    this->setWindowFlags(Qt::FramelessWindowHint);//hint无边框
    //shadow effects
    QGraphicsDropShadowEffect *shadow=new QGraphicsDropShadowEffect();
    shadow->setBlurRadius(20);
    shadow->setColor(Qt::black);
    shadow->setOffset(0);

    ui->shadowWidget->setGraphicsEffect((shadow));

    //this->setGraphicsEffect((shadow));//不理想
    this->setAttribute(Qt::WA_TranslucentBackground);//父窗口设置为透明

    ui->shadowWidget->setWindowFlags(Qt::FramelessWindowHint);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::mouseMoveEvent(QMouseEvent *event)//????
{
    QWidget::mouseMoveEvent(event);//首先invoke父类中的(基本)实现

    QPoint y=event->globalPos();//鼠标移动之后，鼠标相对桌面窗口左上角的向量
    QPoint x=y-this->z;
    this->move(x);//Widget窗口跟着鼠标移动
}

void Widget::mousePressEvent(QMouseEvent *event)//QMouseEvent头文件
{
    QWidget::mousePressEvent(event);

    QPoint y=event->globalPos();//鼠标相对桌面窗口左上角的向量
    QPoint x=this->geometry().topLeft();//Widget窗口左上角相对桌面窗口左上角的向量
    this->z=y-x;//不变的值，鼠标相对Widget窗口左上角的向量
}

void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    QWidget::mouseReleaseEvent(event);
    this->z=QPoint();
}
