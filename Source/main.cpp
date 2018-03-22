#include "mainwindow.h"
#include <QApplication>
#include <QTextStream>

QTextStream cin(stdin);
QTextStream cout(stdout);
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
