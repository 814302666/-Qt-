#include "mylineedit.h"

MyLineEdit::MyLineEdit(QWidget *parent) : QLineEdit(parent)
{

}

void MyLineEdit::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)//鼠标左键点击触发信号
    {
        emit clicked();
    }
}
