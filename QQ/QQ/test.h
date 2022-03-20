#ifndef TEST_H
#define TEST_H

#include <QWidget>
#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <QCameraInfo>
#include <QList>
#include <QDebug>
#include <QImage>


namespace Ui {
class test;
}

class test : public QWidget
{
    Q_OBJECT

public:
    explicit test(QWidget *parent = 0);
    ~test();
    QCamera *camera;//摄像头
    QCameraViewfinder * viewfinder;//摄像头取景器部件
    QCameraImageCapture * imageCapture;//截图部件

public slots:
    void ShowTheCapture();
    void SavePicture();
    void displayImage(int,QImage image);

private:
    Ui::test *ui;
};

#endif // TEST_H
