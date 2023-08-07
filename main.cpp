#include "robotv3.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    robotv3 w;
    w.show();
    return a.exec();
}
