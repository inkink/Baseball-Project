#include "mainwindow.h"
#include <QApplication>
#include <date.h>
#include <stadium.h>
#include <binarytree.h>
#include "stadiumtree.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
