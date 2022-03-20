#include "uart.h"
#include "ui_uart.h"

Uart::Uart(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Uart)
{
    ui->setupUi(this);
}

Uart::~Uart()
{
    delete ui;
}
