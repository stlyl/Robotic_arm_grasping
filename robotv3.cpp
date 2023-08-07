#pragma execution_character_set("utf-8")
#include "robotv3.h"



rs2::pipeline p;

robotv3::robotv3(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    timer = new QTimer(this);
    tcpsocket = NULL;
    tcpsocket = new QTcpSocket(this);
    connect(tcpsocket, &QTcpSocket::connected, [=]() {
        ui.textEditRead->setText("机械臂连接成功！"); });

    //connect(tcpsocket, &QTcpSocket::readyRead, [=]() {
        //获取通信套接字的内容
        //this->server_str = tcpsocket->readAll();
    //ui.textEditRead->append("机械臂端：" + server_str);});
}

robotv3::~robotv3()
{}

void robotv3::on_pushButton_clicked()//tcp连接
{
    QString IP = "192.168.5.1";//机械臂ip
    quint16 Port = 30003;
    tcpsocket->connectToHost(IP, Port);
    if (nullptr == tcpsocket)
    {
        QMessageBox::critical(this, "错误", "连接机械臂失败", QMessageBox::Yes);
    }
}
void robotv3::on_pushButton_5_clicked()//使能机械臂
{
    if (nullptr == tcpsocket)//连接失败则不发送
        return;
    QString str = "EnableRobot()";
    tcpsocket->write(str.toUtf8().data());
    ui.textEditRead->append("机械臂端：机械臂使能成功");
}
void robotv3::on_pushButton_6_clicked()//下使能
{
    if (nullptr == tcpsocket)
        return;
    QString str = "DisableRobot()";
    tcpsocket->write(str.toUtf8().data());
    ui.textEditRead->append("机械臂端：机械臂下使能");
}

void robotv3::on_pushButton_7_clicked()//关闭tcp
{
    if (nullptr == tcpsocket)
        return;
    tcpsocket->disconnectFromHost();//断开与服务器的连接
    tcpsocket->close();//关闭通信套接字
    ui.textEditRead->append("机械臂端：关闭tcp连接");
    timer->stop();
    ui.label->clear();
    ui.label_3->clear();
    ui.label_2->clear();
}
Mat robotv3::Deep_Camera_play()//显示rgb和深度图
{
    rs2::colorizer color_map;
    rs2::frameset data = p.wait_for_frames();//获取图像帧
    rs2::frame depth = data.get_depth_frame().apply_filter(color_map);//获得着色后的深度图像
    const int w = depth.as<rs2::video_frame>().get_width();//获得帧的大小
    const int h = depth.as<rs2::video_frame>().get_height();
    cv::Mat depth_Mat = cv::Mat(Size(w, h), CV_8UC3, (void*)depth.get_data(), cv::Mat::AUTO_STEP);//构造mat类型数据
    //cvtColor(depth_Mat, depth_Mat, CV_BGR2RGB);//对颜色通道进行调整
    QImage depth_QImage = QImage((const unsigned char*)(depth_Mat.data), depth_Mat.cols, depth_Mat.rows, QImage::Format_RGB888);//实现Mat到QImage的转换
    ui.label_3->setPixmap(QPixmap::fromImage(depth_QImage));//显示设置
    ui.label_3->setFixedSize(480, 260);
    ui.label_3->setScaledContents(true);
    rs2::frame color = data.get_color_frame();//同上
    const int cw = color.as<rs2::video_frame>().get_width();
    const int ch = color.as<rs2::video_frame>().get_height();
    cv::Mat color_Mat = cv::Mat(Size(cw, ch), CV_8UC3, (void*)color.get_data(), Mat::AUTO_STEP);//构造mat类型数据
    QImage color_QImage = QImage((const unsigned char*)(color_Mat.data),
        color_Mat.cols, color_Mat.rows, QImage::Format_RGB888);
    ui.label->setPixmap(QPixmap::fromImage(color_QImage));
    ui.label->setFixedSize(480, 260);
    ui.label->setScaledContents(true);
    return color_Mat;
}

void robotv3::moveL(QString str2)
{
    
    tcpsocket->write(str2.toUtf8().data());

}
void robotv3::Delay_MSec(unsigned int msec)
{
    QEventLoop loop;
    QTimer::singleShot(msec, &loop, SLOT(quit()) );
    loop.exec();
}

void robotv3::update()//显示时间
{
    QTime time = QTime::currentTime();
    ui.label->setText(tr("%1").arg(time.toString()));
}
void robotv3::on_pushButton_3_clicked()
{
    p.start();
    //Deep_Camera_play();
    connect(timer, SIGNAL(timeout()), this, SLOT(Recognize()));
    //connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(100);
    QString str1 = "MovJ(-373.5886,-106.7937,314.3545,178.8206,-1.1113,95.5338)";
    tcpsocket->write(str1.toUtf8().data());
    ui.textEditRead->append("机械臂端：目标物体检测");
    
}
void robotv3::on_pushButton_8_clicked()
{
    ui.textEditRead->append("机械臂端：开始抓取");
    QString str2 = "MovJ(-503.1188,-85.5070,119.3569,176.3569,-1.0254,93.9515)";
    //tcpsocket->write(str2.toUtf8().data());
    this->moveL(str2);
    Delay_MSec(5000);
    //Arc(X1,Y1,Z1,Rx1,Ry1,Rz1,X2,Y2,Z2,Rx2,Ry2,Rz2)
    QString str11 = "MovJ(-373.5886,-106.7937,314.3545,178.8206,-1.1113,95.5338)";
    this->moveL(str11);
    Delay_MSec(1000);
    //tcpsocket->write(str3.toUtf8().data());
    QString str3 = "MovJ(-94.6895,-573.1969,130.5208,179.1109,-2.0760,166.7360)";
    this->moveL(str3);
    //tcpsocket->write(str3.toUtf8().data());
    Delay_MSec(5000);

    QString str4 = "MovJ(-373.5886,-106.7937,314.3545,178.8206,-1.1113,95.5338)";
    this->moveL(str4);
    //tcpsocket->write(str4.toUtf8().data());
    Delay_MSec(5000);
    ui.textEditRead->append("机械臂端：机械臂抓取成功" );
    QString str6 = "MovJ(-464.5685,-187.1589,121.3144,175.2782,-0.7795,105.9672)";
    //tcpsocket->write(str2.toUtf8().data());
    this->moveL(str6);
    Delay_MSec(5000);
    QString str7 = "MovJ(-373.5886,-106.7937,314.3545,178.8206,-1.1113,95.5338)";
    //tcpsocket->write(str2.toUtf8().data());
    this->moveL(str7);
    Delay_MSec(5000);
    QString str8 = "MovJ(-94.6895,-573.1969,130.5208,179.1109,-2.0760,166.7360)";
    this->moveL(str8);
    //tcpsocket->write(str3.toUtf8().data());
    Delay_MSec(5000);
    QString str9 = "MovJ(-373.5886,-106.7937,314.3545,178.8206,-1.1113,95.5338)";
    //tcpsocket->write(str2.toUtf8().data());
    this->moveL(str9);
    Delay_MSec(5000);
    ui.textEditRead->append("机械臂端：机械臂抓取成功");
}
void robotv3::Recognize()//图像处理提取
{
    cv::Mat imgHSV; vector<Mat> hsvSplit; Mat colorMat2; Mat colorMat5;
    cv::Mat colorMat_rgb;
    cv::Mat colorMat1 = Deep_Camera_play();//BGR
    cv::cvtColor(colorMat1, colorMat_rgb, CV_BGR2RGB);
    cv::GaussianBlur(colorMat_rgb, colorMat2, Size(3, 3), 0);//高斯模糊
    cv::cvtColor(colorMat2, imgHSV, COLOR_BGR2HSV);//转HSV
    cv::split(imgHSV, hsvSplit);
    cv::equalizeHist(hsvSplit[2], hsvSplit[2]);
    cv::merge(hsvSplit, imgHSV);//直方图均衡化
    //颜色检测
    cv::inRange(imgHSV, Scalar(75, 90, 90), Scalar(130, 255, 255), colorMat5);
    //inRange(imgHSV, Scalar(75, 90, 90), Scalar(130, 255, 255), colorMat5);
    cv::Mat imgThresholded; Mat img_close;
    cv::Mat element = getStructuringElement(MORPH_RECT, Size(3, 3));//开操作 (去除一些噪点)
    cv::morphologyEx(colorMat5, imgThresholded, MORPH_OPEN, element);
    //闭操作 (连接一些连通域)
    cv::morphologyEx(imgThresholded, img_close, MORPH_CLOSE, element);
    cv::Canny(img_close, img_close, 100, 200, 3, false);
    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
    cv::findContours(img_close, contours, hierarchy, RETR_TREE,
        CHAIN_APPROX_SIMPLE, Point(0, 0));
    vector<Moments> mu(contours.size());
    for (int i = 0; i < contours.size(); i++)
    {
        mu[i] = cv::moments(contours[i], false);
    }
    //计算轮廓中心
    vector<Point2f>  mc(contours.size());
    for (int i = 0; i < contours.size(); i++)
    {

        int cx = mu[i].m10 / mu[i].m00;
        int cy = mu[i].m01 / mu[i].m00;
        mc[i] = cv::Point2d(mu[i].m10 / mu[i].m00, mu[i].m01 / mu[i].m00);
        //ui.label->setText("物体区域中心坐标:(" + QString::number(cx) + "," + QString::number(cy) + ")");
    }
    //绘制轮廓标定形心
    cv::Mat drawing = cv::Mat::zeros(img_close.size(), CV_8UC3);
    for (int i = 0; i < contours.size(); i++)
    {
        cv::Scalar color = cv::Scalar(0, 255, 0);
        //第一个变量用初始图像可以将轮廓绘制到原图上
        cv::drawContours(colorMat_rgb, contours, i, color, 2, 8, hierarchy, 0, Point(0, 0));
        //指的是标定形心
        cv::circle(colorMat_rgb, mc[i], 10, Scalar(0, 0, 255), -1, 6, 0);      //画中心圆
    }
    cv::cvtColor(colorMat_rgb, colorMat_rgb, CV_BGR2RGB);
    QImage color_QImage = QImage((const unsigned char*)(colorMat_rgb.data),
        colorMat_rgb.cols, colorMat_rgb.rows, QImage::Format_RGB888);
    ui.label_2->setPixmap(QPixmap::fromImage(color_QImage));
    ui.label_2->setFixedSize(480, 260);
    ui.label_2->setScaledContents(true);
}