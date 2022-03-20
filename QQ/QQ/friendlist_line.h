#ifndef FRIENDLIST_LINE_H
#define FRIENDLIST_LINE_H

#include <QWidget>
#include <qtoolbutton.h>

namespace Ui {
class Friendlist_line;
}

class Friendlist_line : public QWidget
{
    Q_OBJECT

public:
    explicit Friendlist_line(QWidget *parent,QString username,bool isonlive);
    void change_state(bool isonlive);
    ~Friendlist_line();

signals:
    void mycliked();

private:
    Ui::Friendlist_line *ui;
};

#endif // FRIENDLIST_LINE_H
