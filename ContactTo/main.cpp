#include "QWMain.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/images/images/appicon.ico"));
    QWMain w;
    w.show();
    return a.exec();
}
