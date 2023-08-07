#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_robotv3.h"
#include<QMessageBox>
#include <QTcpSocket>
#include <Qdebug>
#include <QTimer>
#include <QTime>

#include <librealsense2/rs.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/core/core.hpp>
#include "opencv2/imgproc/types_c.h"
//using namespace cv;

#include<windows.h>
#include <iostream>
using namespace std;

#include "mywork.h"
#include <QThread>




class robotv3 : public QMainWindow
{
    Q_OBJECT

public:
    robotv3(QWidget *parent = nullptr);
    ~robotv3();
    QTimer* timer;//ˢ�¶�ʱ��

private:
    Ui::robotv3Class ui;
    QTcpSocket* tcpsocket; //ͨ���׽���
    QString server_str; //ͨ���׽��ֵ�����

    //rs2::pipeline* p = nullptr;
    MyWork* work;//�Զ����̶߳���
    QThread* thread;

private slots:
    void on_pushButton_clicked();//tcp����
    void on_pushButton_5_clicked();//ʹ�ܻ�е��
    void on_pushButton_6_clicked();//��ʹ��
    void on_pushButton_7_clicked();//�ر�tcp
    void on_pushButton_3_clicked();//�������
    void on_pushButton_8_clicked();//ץȡ
    Mat Deep_Camera_play();
    void update();
    void Recognize();

    void moveL(QString data);
    void Delay_MSec(unsigned int msec);
    


};
