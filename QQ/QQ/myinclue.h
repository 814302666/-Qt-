#ifndef MYINCLUE_H
#define MYINCLUE_H


#include <QWidget>
#include <QUdpSocket>
#include <QHash>
#include <QToolButton>
#include <QPoint>
#include <QMouseEvent>
#include <QListWidget>
#include <QListWidgetItem>
#include <QLabel>
#include <QToolButton>
#include <QMessageBox>
#include <QPushButton>
#include <QTime>
#include <QColor>
#include <QColorDialog>
#include <QSettings>
#include <QTcpServer>
#include <QTcpSocket>
#include <QFile>
#include <QFileDialog>
#include <QSpacerItem>
#include <QSqlQuery>
#include <QSqlError>
#include <QFileInfo>
#include <QSqlRecord>
#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <QTimer>
#include <QBuffer>
#include <QAudio>
#include <QAudioFormat>
#include <QAudioInput>
#include <QAudioOutput>
#include <QIODevice>

class MyInclue
{
public:
    enum MsgType{
        Login,//登录
        Register,//注册
        GetFriend,//获得好友
        Updata,//信息更新
        SendMsg,//发送信息
        Exit,//下线
        SearchFriend,//查找好友
        AddFriend,//添加好友
        AgreeAddFriend,//同意添加好友
        GetFriendIp,//获取好友IP
        SendFile,//发送文件
        StartListen,//开始监听 表明已建立tcp服务器
        OfflineFile,//询问是否有离线文件
        OfflineFileListen,//TCP已建立
        VideoChat,//建立视频连接
        VoiceChat,//语音聊天
     };
    MyInclue();

};

#endif // MYINCLUE_H
