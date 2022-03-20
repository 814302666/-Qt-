#include "friendlist_line.h"
#include "ui_friendlist_line.h"

Friendlist_line::Friendlist_line(QWidget *parent,QString username,bool isonlive) :
    QWidget(parent),
    ui(new Ui::Friendlist_line)
{
    //图标
    ui->setupUi(this);
    ui->icon->setIcon(QPixmap(QString(":/image/%1.jpg").arg(username)));
    ui->icon->setIconSize(QSize(100,100));
    ui->icon->setAutoRaise(true);
    ui->icon->setToolButtonStyle(Qt::ToolButtonIconOnly);
    //用户名
    ui->name->setText(username);
    ui->name->setStyleSheet("color:black");
    //在线状态
    QString s;
    if(isonlive)
    {
        s = "已上线";
        ui->state->setText(s);
        ui->state->setStyleSheet("color:green");
    }
    else
    {
        s = "已离线";
        ui->state->setText(s);
        ui->state->setStyleSheet("color:red");
    }
    connect(ui->icon,&QToolButton::clicked,[=](){
        emit mycliked();
    });
}

void Friendlist_line::change_state(bool isonlive)
{
    QString s;
    if(isonlive)
    {
        s = "已上线";
        ui->state->setText(s);
        ui->state->setStyleSheet("color:green");
    }
    else
    {
        s = "已离线";
        ui->state->setText(s);
        ui->state->setStyleSheet("color:red");
    }
}

Friendlist_line::~Friendlist_line()
{
    delete ui;
}
