#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);//QT必要

    Widget w;
    w.show();

    return a.exec();//事件循环
}
