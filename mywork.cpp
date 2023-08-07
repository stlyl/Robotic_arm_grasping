#pragma execution_character_set("utf-8")
#include "mywork.h"
#include <QDebug>
#include <QThread>

MyWork::MyWork(QObject* parent) :
    QObject(parent)
{
}

void MyWork::working()
{
    qDebug() << "��ǰ�̶߳���ĵ�ַ: " << QThread::currentThread();
    int num = 0;
    while (1)
    {
        //ʹ�� emit ��ǡ����λ�÷����źţ�
        num = num + 1;
        //emit curNumber(num);
        emit cur(num);
        if (num == 500)
        {
            break;
        }
        QThread::usleep(1);
    }
    qDebug() << "run() ִ�����, ���߳��˳�...";
}
void MyWork::rs()
{
    /*qDebug() << "�������̶߳���ĵ�ַ: " << QThread::currentThread();
    Mat image = imread("C:/Users/LYL/Desktop/Sni.jpg");
    imshow("���봰��", image);
    cvtColor(image, image, CV_BGR2RGB);
    QImage color_QImage = QImage((const unsigned char*)(image.data),
        image.cols, image.rows, QImage::Format_RGB888);
    emit cur_image(color_QImage);
    QThread::usleep(1);
    qDebug() << "run() ִ�����, ���߳��˳�...";*/

    qDebug() << "�������̶߳���ĵ�ַ: " << QThread::currentThread();
    p = new rs2::pipeline;
    p->start();
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(Deep_Camera_play()));
    timer->start(1000);
}
void MyWork::Deep_Camera_play()
{
    rs2::colorizer color_map;
    rs2::frameset data = p->wait_for_frames();//��ȡͼ��֡
    rs2::frame color = data.get_color_frame();//ͬ��
    const int cw = color.as<rs2::video_frame>().get_width();
    const int ch = color.as<rs2::video_frame>().get_height();
    Mat color_Mat = Mat(Size(cw, ch), CV_8UC3, (void*)color.get_data(), Mat::AUTO_STEP);
    QImage color_QImage = QImage((const unsigned char*)(color_Mat.data),
        color_Mat.cols, color_Mat.rows, QImage::Format_RGB888);
    emit cur_image(color_QImage);
}
void MyWork::close_video()
{
    p->stop();
    timer->stop();
    delete p;
}