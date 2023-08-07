/********************************************************************************
** Form generated from reading UI file 'robotv3.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROBOTV3_H
#define UI_ROBOTV3_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_robotv3Class
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_8;
    QTextEdit *textEditRead;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *robotv3Class)
    {
        if (robotv3Class->objectName().isEmpty())
            robotv3Class->setObjectName(QString::fromUtf8("robotv3Class"));
        robotv3Class->resize(1274, 838);
        centralWidget = new QWidget(robotv3Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(50, 40, 401, 30));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_5 = new QPushButton(layoutWidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        horizontalLayout->addWidget(pushButton_5);

        pushButton_6 = new QPushButton(layoutWidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        horizontalLayout->addWidget(pushButton_6);

        pushButton_7 = new QPushButton(layoutWidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));

        horizontalLayout->addWidget(pushButton_7);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(50, 80, 195, 31));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_3 = new QPushButton(layoutWidget1);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout_2->addWidget(pushButton_3);

        pushButton_8 = new QPushButton(layoutWidget1);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));

        horizontalLayout_2->addWidget(pushButton_8);

        textEditRead = new QTextEdit(centralWidget);
        textEditRead->setObjectName(QString::fromUtf8("textEditRead"));
        textEditRead->setGeometry(QRect(560, 510, 511, 151));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(31, 221, 39, 16));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(580, 220, 60, 16));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 500, 45, 16));
        robotv3Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(robotv3Class);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1274, 26));
        robotv3Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(robotv3Class);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        robotv3Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(robotv3Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        robotv3Class->setStatusBar(statusBar);

        retranslateUi(robotv3Class);

        QMetaObject::connectSlotsByName(robotv3Class);
    } // setupUi

    void retranslateUi(QMainWindow *robotv3Class)
    {
        robotv3Class->setWindowTitle(QApplication::translate("robotv3Class", "303\351\207\215\347\202\271\345\256\236\351\252\214\345\256\244--\345\237\272\344\272\216\346\234\272\345\231\250\350\247\206\350\247\211\347\232\204\346\231\272\350\203\275\345\210\206\346\213\243\347\263\273\347\273\237", nullptr));
        pushButton->setText(QApplication::translate("robotv3Class", "\350\277\236\346\216\245\346\234\272\346\242\260\350\207\202", nullptr));
        pushButton_5->setText(QApplication::translate("robotv3Class", "\344\275\277\350\203\275\346\234\272\346\242\260\350\207\202", nullptr));
        pushButton_6->setText(QApplication::translate("robotv3Class", "\344\270\213\344\275\277\350\203\275\346\234\272\346\242\260\350\207\202", nullptr));
        pushButton_7->setText(QApplication::translate("robotv3Class", "\345\205\263\351\227\255\350\277\236\346\216\245", nullptr));
        pushButton_3->setText(QApplication::translate("robotv3Class", "\347\233\256\346\240\207\346\243\200\346\265\213", nullptr));
        pushButton_8->setText(QApplication::translate("robotv3Class", "\346\212\223\345\217\226", nullptr));
        label->setText(QApplication::translate("robotv3Class", "RGB\346\265\201", nullptr));
        label_2->setText(QApplication::translate("robotv3Class", "\346\243\200\346\265\213\350\247\206\345\233\276", nullptr));
        label_3->setText(QApplication::translate("robotv3Class", "\346\267\261\345\272\246\346\265\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class robotv3Class: public Ui_robotv3Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROBOTV3_H
