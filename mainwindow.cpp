#include "mainwindow.h"
#include "ui_mainwindow.h"

//file path for input.txt
string filepath = "/Users/Jason/Documents/School/Spring 2017/CS 8/Baseball Project/Baseball-Project-GIT/";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    loadStadiumInfo(filepath + "input.txt");
    stadiums.displayInOrder();
    ui->setupUi(this);
}

//destructor
MainWindow::~MainWindow()
{
    delete ui;
}

//load the information from the file into the
//stadium tree
void MainWindow::loadStadiumInfo(string filename)
{
    ifstream ifile;
    ifile.open(filename);

    if (ifile.is_open()){

        std::string temp, team, stadium, state, phone, address;
        int cap, month, day, year;
        bool grass, league;

        while (getline(ifile, temp)){
            //team name
            stadium = temp;

            //stadium name
            getline(ifile,temp);
            team = temp;

            //address
            getline(ifile,temp);
            address = temp;

            //state
            getline(ifile,temp);
            state = temp;

            //phone
            getline(ifile,temp);
            phone = temp;

            //open date
            getline(ifile,temp,'/');
            month = std::stoi(temp);
            getline(ifile,temp,'/');
            day = std::stoi(temp);
            getline(ifile,temp,'\n');
            year = std::stoi(temp);

            //capacity
            getline(ifile,temp);
            cap = std::stoi(temp);

            //grass
            getline(ifile,temp);
            grass = std::stoi(temp);

            //leaguetype
            getline(ifile,temp);
            league = std::stoi(temp);

            stadiums.insertNode(Stadium(team, stadium, address, state, phone, Date(month,day,year),
                                    cap, league, grass));

            getline(ifile,temp);
        }
    }
    ifile.clear();
    ifile.close();
}



//display all the stadiums on the table
void MainWindow::displayAllStadiums()
{
    clearTable();

    ui->tableWidget->setColumnCount(8);
//    ui->tableWidget->setColumnWidth(0,150);
//    ui->tableWidget->setColumnWidth(1,75);
//    ui->tableWidget->setColumnWidth(5,75);
    std::string labels = "Stadium,Team,Address,Phone,Open Date,Capacity,Grass,League";
    ui->tableWidget->setHorizontalHeaderLabels(QString::fromStdString(labels).split(","));

    stadiums.DisplayTableInOrder(ui->tableWidget);
}

/**********************************************************
 * void MainWindow::clearTable()
 * _______________________________________________________
 * Precondition:
 *  - nothing
 * Postcondition:
 *  - clears the table
**********************************************************/
void MainWindow::clearTable()
{
    ui->tableWidget->clear();
    ui->tableWidget->reset();
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(0);
    ui->tableTitleLabel->clear();
}
