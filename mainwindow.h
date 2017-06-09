#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "stadium.h"
#include "souvenir.h"
#include "binarytree.h"
#include "stadiumtree.h"
#include "stadiumdatetree.h"
#include "stadiumteamtree.h"
#include "shoppingcart.h"
#include <fstream>
#include <QMessageBox>
#include <graph.h>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void loadStadiumInfo(string filename);
    void displayMsgBox(std::string message) const;
    void showStartingPoints();
    ~MainWindow();

public slots:
    void displayAllStadiums();
    void listSouvenir();
    void buySouvenir();
    void addSouvenir();
    void removeSouvenir();
    void modifySouvenir();
    void displayCart();
    void clearTable();
    void addNewStadium();
    void setAdminMode();
    void setUserMode();
    void createNewTrip();
    void updateVisit();

private:
    Ui::MainWindow *ui;
    StadiumTree stadiums;
    StadiumDateTree date_stadiums;
    StadiumTeamTree team_stadiums;
    //test for souvenir
    Stadium current;
    ShoppingCart cart;
    vector<int> allTrip;
    vector<int> nationalTrip;
    vector<int> americanTrip;
    int tripLength;
    int currentTrip;


};

#endif // MAINWINDOW_H
