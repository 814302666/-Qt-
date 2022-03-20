#include "voice.h"
#include "ui_voice.h"

voice::voice(QWidget *parent,QString name,QString fname) :
    QWidget(parent),
    ui(new Ui::voice)
{
    ui->setupUi(this);
    myname = name;
    friend_name = fname;

    udpSocket= new QUdpSocket(this);
    //绑定10004端口
    udpSocket->bind(10004);

    ui->headbtn->setIcon(QIcon(QString(":/image/%1.jpg").arg(myname)));
    ui->headbtn->setIconSize(QSize(150,150));
    ui->headbtn->move(125,100);
    ui->headbtn->setAutoRaise(true);

    ui->closebtn->setIconSize(QSize(150,150));
    ui->closebtn->move(125,400);
    ui->closebtn->setAutoRaise(true);

    //定义音频处理的类型
    QAudioFormat format;
    //采集频率为1s 8000次
    format.setSampleRate(8000);
    //设定声道数目，mono(平声道)的声道数目是1；stero(立体声)的声道数目是2
    format.setChannelCount(1);
    //设定采样大小，8也行，发送端和接收端要一致
    format.setSampleSize(16);
    //设定为PCM编码
    format.setCodec("audio/pcm");

    format.setSampleType(QAudioFormat::SignedInt);
    //设定高低位,LittleEndian（低位优先）/LargeEndian(高位优先)
    format.setByteOrder(QAudioFormat::LittleEndian);
    //获取默认的音频输入设备，判断是否支持指定的格式，如果不支持则使用一个邻近的格式
    QAudioDeviceInfo info = QAudioDeviceInfo::defaultInputDevice();
    if (!info.isFormatSupported(format))
    {
        format = info.nearestFormat(format);
    }

    input = new QAudioInput(format,this);
    //input开始读入输入的音频信号，写入QIODevice
    inputDevice = input->start();
    output = new QAudioOutput(format, this);
    outputDevice = output->start ();
    //槽函数，当inputDevice收到input写入的音频数据之后,调用onReadyRead函数，发送数据到目标主机上
    connect(inputDevice,SIGNAL(readyRead()),this,SLOT(onReadyRead()));
    connect(udpSocket,SIGNAL(readyRead()),this,SLOT(ReadyReadSlot()));

    //关闭按钮
    connect(ui->closebtn,&QToolButton::clicked,[=](){
        emit close_sig();
    });

}

voice::~voice()
{
    input->stop();
    output->stop();
    delete output;
    delete input;
    delete ui;
}

void voice::onReadyRead(){

    qDebug()<<"It's sending audio!"<<endl;
    video vp;
    memset(&vp,0,sizeof(vp));

    //读取音频
    vp.lens = inputDevice->read(vp.audiodata,1024);
    //将此结构体发送给目标主机，端口是10004
    udpSocket->writeDatagram((const char*)&vp,sizeof(vp),QHostAddress::Broadcast,10004);

}

void voice::ReadyReadSlot()
{
    qDebug() << "video reveiver...";
    video vp1;
    memset(&vp1, 0, sizeof(vp1));
    udpSocket->readDatagram ((char*)&vp1, sizeof(vp1));
    outputDevice->write(vp1.audiodata, vp1.lens);
}
