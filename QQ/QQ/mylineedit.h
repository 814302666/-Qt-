#ifndef MYLINEEDIT_H
#define MYLINEEDIT_H

#include <QWidget>
#include <QLineEdit>
#include <QMouseEvent>

class MyLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit MyLineEdit(QWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent *e);

signals:
    void clicked();

};

#endif // MYLINEEDIT_H
