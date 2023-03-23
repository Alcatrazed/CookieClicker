#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    MainWindow w = MainWindow();
    w.resize(2000,2000);
    w.show();



    return a.exec();
}
