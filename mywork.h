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
    Q_OBJECT // 宏定义,才能使用QT中的signal和slot机制。
public:
    //C++中的explicit关键字通常用来将构造函数标记为显式类型转换
    //即在创建对象的时候不能进行隐式类型转换。
    explicit MyWork(QObject* parent = nullptr);
    // 工作函数
    void working();
    void rs();
    void close_video();

    rs2::pipeline* p = nullptr;
    QTimer* timer;//刷新定时器

signals:
    void cur(int num);
    void cur_image(QImage image);
public slots:
    void Deep_Camera_play();
};

#endif // MYWORK_H