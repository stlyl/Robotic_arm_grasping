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
    QTimer* timer;//刷新定时器

private:
    Ui::robotv3Class ui;
    QTcpSocket* tcpsocket; //通信套接字
    QString server_str; //通信套接字的内容

    //rs2::pipeline* p = nullptr;
    MyWork* work;//自定义线程对象
    QThread* thread;

private slots:
    void on_pushButton_clicked();//tcp连接
    void on_pushButton_5_clicked();//使能机械臂
    void on_pushButton_6_clicked();//下使能
    void on_pushButton_7_clicked();//关闭tcp
    void on_pushButton_3_clicked();//相机调试
    void on_pushButton_8_clicked();//抓取
    Mat Deep_Camera_play();
    void update();
    void Recognize();

    void moveL(QString data);
    void Delay_MSec(unsigned int msec);
    


};
