#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);//explict防止隐式类型转化
    ~Widget();

    //override父类中的virtual函数，QWidget的press move release三个事件
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);


private:
    Ui::Widget *ui;//加了shadowWidget,用于实现Drop shadow
    QPoint z;//实现Widget拖动，用于两个成员函数间的通信
};

#endif // WIDGET_H
