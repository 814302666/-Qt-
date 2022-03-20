#ifndef SERIALPORT_H
#define SERIALPORT_H

#include <QWidget>

namespace Ui {
class Serialport;
}

class Serialport : public QWidget
{
    Q_OBJECT

public:
    explicit Serialport(QWidget *parent = 0);
    ~Serialport();

private:
    Ui::Serialport *ui;
};

#endif // SERIALPORT_H
