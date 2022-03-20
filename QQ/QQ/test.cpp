#include "test.h"
#include "ui_test.h"
#include <QTimer>
int index = 0;

test::test(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::test)
{
    ui->setupUi(this);
    camera=new QCamera;//摄像头
    viewfinder=new QCameraViewfinder(this);
    imageCapture=new QCameraImageCapture(camera);//截图部件
//    camera->setViewfinder(viewfinder);
//    viewfinder->move(100,100);

//    QObject::connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(ShowTheCapture()));
//    QObject::connect(ui->SaveButton,SIGNAL(clicked()),this,SLOT(SavePicture()));
    QObject::connect(imageCapture, SIGNAL(imageCaptured(int,QImage)), this, SLOT(displayImage(int,QImage)));
    imageCapture->setCaptureDestination(QCameraImageCapture::CaptureToFile);
    camera->setCaptureMode(QCamera::CaptureStillImage);
    camera->setViewfinder(viewfinder);
    camera->start(); //启动摄像头

    QTimer *mytimer = new QTimer(this);
    connect(mytimer,&QTimer::timeout,[=](){
        imageCapture->capture();
    });
    mytimer->start(1000);
    ui->verticalLayout_2->addWidget(viewfinder,0,Qt::AlignTop);
    viewfinder->resize(QSize(200,200));
}

void test::ShowTheCapture()
{
    imageCapture->capture();
}
void test::displayImage(int ,QImage image)
{
    image=image.convertToFormat(QImage::Format_RGB888);
    image.save(QString("E:\\picture\\%1.jpg").arg(index));
    index++;
    ui->label->setPixmap(QPixmap::fromImage(image));
    QImage::Format format =  image.format();
    qDebug() << (int)format;

}
void test::SavePicture()
{
    const QPixmap *pixmap = ui->label->pixmap();
    if(pixmap)
    {
         pixmap->save("E:\\hallo.jpg");
         qDebug()<<"保存上了"<<endl;
    }

}

test::~test()
{
    delete ui;
}
