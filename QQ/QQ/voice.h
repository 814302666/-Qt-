#ifndef VOICE_H
#define VOICE_H

#include <QWidget>
#include <myinclue.h>

namespace Ui {
class voice;
}

class voice : public QWidget
{
    Q_OBJECT

public:
    explicit voice(QWidget *parent,QString name,QString fname);
    ~voice();

private slots:
    void onReadyRead();
    void ReadyReadSlot();

signals:
    void close_sig();

private:
    Ui::voice *ui;
    QUdpSocket *udpSocket;//用于音频信号的发送
    QString ip;
    QAudioInput *input;
    QAudioOutput *output;
    QIODevice *inputDevice;
    QIODevice *outputDevice;
    static int i;
    struct video
    {
        char audiodata[1024];
        int lens;
    };
    QString myname;
    QString friend_name;
};

#endif // VOICE_H
