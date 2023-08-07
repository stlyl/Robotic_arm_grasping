#pragma once
#ifndef MYWORK_H
#define MYWORK_H

#include <QObject>
#include <QImage>

#include <librealsense2/rs.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/core/core.hpp>
#include "opencv2/imgproc/types_c.h"
using namespace cv;

#include <QTimer>

class MyWork : public QObject
{
    Q_OBJECT // �궨��,����ʹ��QT�е�signal��slot���ơ�
public:
    //C++�е�explicit�ؼ���ͨ�����������캯�����Ϊ��ʽ����ת��
    //���ڴ��������ʱ���ܽ�����ʽ����ת����
    explicit MyWork(QObject* parent = nullptr);
    // ��������
    void working();
    void rs();
    void close_video();

    rs2::pipeline* p = nullptr;
    QTimer* timer;//ˢ�¶�ʱ��

signals:
    void cur(int num);
    void cur_image(QImage image);
public slots:
    void Deep_Camera_play();
};

#endif // MYWORK_H