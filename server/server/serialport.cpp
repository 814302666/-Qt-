#include "serialport.h"
#include "ui_serialport.h"

Serialport::Serialport(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Serialport)
{
    ui->setupUi(this);
}

Serialport::~Serialport()
{
    delete ui;
}
