#ifndef UART_H
#define UART_H

#include <QWidget>

namespace Ui {
class Uart;
}

class Uart : public QWidget
{
    Q_OBJECT

public:
    explicit Uart(QWidget *parent = 0);
    ~Uart();

private:
    Ui::Uart *ui;
};

#endif // UART_H
