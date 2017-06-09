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
    explicit MainWindow(QWidget *parent = 0);       //constructor
    void loadStadiumInfo(string filename);          //loads stadium info
    void displayMsgBox(std::string message) const;  //displays the msg box
    void showStartingPoints();                      //display starting point
    ~MainWindow();                                  //destructor

public slots:
    void displayAllStadiums();                      //display all stadium info
    void listSouvenir();                            //lists available souvenirs
    void buySouvenir();                             //buys souvenir
    void addSouvenir();                             //add new souvenir to shop
    void removeSouvenir();                          //remove souvenir from shop
    void modifySouvenir();                          //modify souvenir info
    void displayCart();                             //displays bought souvenirs
    void clearTable();                              //clears table text
    void addNewStadium();                           //add new stadium
    void setAdminMode();                            //enables admin commands
    void setUserMode();                             //disables admin commands
    void createNewTrip();                           //create a user picked trip
    void updateVisit();                             //updates stadiums visited

private:
    Ui::MainWindow *ui;                             //ui pointer
    StadiumTree stadiums;                           //tree of stadiums sorted by stadium
    StadiumDateTree date_stadiums;                  //tree of stadiums sorted by date
    StadiumTeamTree team_stadiums;                  //tree of stadiums sorted by team
    Stadium current;                                //current stadium visited
    ShoppingCart cart;                              //cart of purchased souvenirs
    vector<int> allTrip;                            //list of all stadiums in trip
    vector<int> nationalTrip;                       //list of national stadiums in trip
    vector<int> americanTrip;                       //list of american stadiums in trip
    int tripLength;                                 //size of trip
    int currentTrip;                                //current trip value


};

#endif // MAINWINDOW_H
