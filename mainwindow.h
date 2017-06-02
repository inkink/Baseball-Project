#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "stadium.h"
#include "souvenir.h"
#include "binarytree.h"
#include "stadiumtree.h"
#include "stadiumdatetree.h"
#include <fstream>
#include <QMessageBox>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void loadStadiumInfo(string filename);
    void loadDateStadiumInfo(string filename);
    void displayMsgBox(std::string message) const;
    ~MainWindow();

public slots:
    void displayAllStadiums();
    void clearTable();

private:
    Ui::MainWindow *ui;
    StadiumTree stadiums;
    StadiumDateTree date_stadiums;

};

#endif // MAINWINDOW_H
