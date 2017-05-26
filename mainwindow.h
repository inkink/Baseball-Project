#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "stadium.h"
#include "souvenir.h"
#include "binarytree.h"
#include "stadiumtree.h"
#include <fstream>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void loadStadiumInfo(string filename);
    ~MainWindow();

public slots:
    void displayAllStadiums();
    void clearTable();

private:
    Ui::MainWindow *ui;
    StadiumTree stadiums;

};

#endif // MAINWINDOW_H
