#include "mainwindow.h"
#include "ui_mainwindow.h"

//file path for input.txt
string filepath = "/Users/Jason/Documents/School/Spring 2017/CS 8/Baseball Project/Baseball-Project-GIT/";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    loadStadiumInfo(filepath + "input.txt");
    loadDateStadiumInfo(filepath + "input.txt");
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

//load the information from the file into the
//stadium tree
void MainWindow::loadDateStadiumInfo(string filename)
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

            date_stadiums.insertNode(Stadium(team, stadium, address, state, phone, Date(month,day,year),
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

    if (ui->displayAllRadio->isChecked()){
        if (ui->dateSortRadio->isChecked()){
            date_stadiums.DisplayTableInOrder(ui->tableWidget);
            ui->tableTitleLabel->setText("List of all Stadium Information by Name");
        }
        else{
            stadiums.DisplayTableInOrder(ui->tableWidget);
            ui->tableTitleLabel->setText("List of all Stadium Information by Date");
        }
    }
    else if (ui->displayNationalRadio->isChecked()){
        if (ui->dateSortRadio->isChecked()){
            date_stadiums.DisplayNational(ui->tableWidget);
            ui->tableTitleLabel->setText("List of National Stadium Information by Name");
        }
        else{
            stadiums.DisplayNational(ui->tableWidget);
            ui->tableTitleLabel->setText("List of National Stadium Information by Date");
            }
    }
    else if (ui->displayAmericanRadio->isChecked()){
        if (ui->dateSortRadio->isChecked()){
            date_stadiums.DisplayAmerican(ui->tableWidget);
            ui->tableTitleLabel->setText("List of American Stadium Information by Name");
        }
        else{
            stadiums.DisplayAmerican(ui->tableWidget);
            ui->tableTitleLabel->setText("List of American Stadium Information by Date");
            }
    }
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

/**********************************************************
 * void MainWindow::displayMsgBox(std::string message) const
 * _______________________________________________________
 * Precondition:
 *  - none
 * Postcondition:
 *  - displays a message box with message
**********************************************************/
void MainWindow::displayMsgBox(std::string message) const
{
    QMessageBox msgbox;
    msgbox.setText(QString::fromStdString(message));
    msgbox.exec();
}
