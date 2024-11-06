#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QApplication::setStyle("windowsvista");
    w.setWindowTitle("Vole Machine");
    w.show();
    return a.exec();
}
