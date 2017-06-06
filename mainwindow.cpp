#include "mainwindow.h"
#include "ui_mainwindow.h"

//file path for input.txt
//string filepath = "/C:/Users/Administrator/Desktop/CS8/Project2/build-Baseball-Project-Desktop_Qt_5_7_0_MinGW_32bit-Debug/";
string filepath = "/Users/Jason/Documents/School/Spring 2017/CS 8/Baseball Project/";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
//    loadStadiumInfo("input.txt");
//    ui->setupUi(this);
    loadStadiumInfo(filepath + "input.txt");
    ui->setupUi(this);
    ui->tabWidget->setCurrentIndex(0);
    ui->tabWidget->setTabEnabled(3,false);
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
            date_stadiums.insertNode(Stadium(team, stadium, address, state, phone, Date(month,day,year),
                                    cap, league, grass));
            team_stadiums.insertNode(Stadium(team, stadium, address, state, phone, Date(month,day,year),
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
            ui->tableTitleLabel->setText("List of all Stadium Information by Date");
        }
        else if(ui->teamSortRadio->isChecked()){
            team_stadiums.DisplayTableInOrder(ui->tableWidget);
            ui->tableTitleLabel->setText("List of all Stadium Information by Team Name");
        }
        else{
            stadiums.DisplayTableInOrder(ui->tableWidget);
            ui->tableTitleLabel->setText("List of all Stadium Information by Stadium Name");
        }
    }
    else if (ui->displayNationalRadio->isChecked()){
        if (ui->dateSortRadio->isChecked()){
            date_stadiums.DisplayNational(ui->tableWidget);
            ui->tableTitleLabel->setText("List of National Stadium Information by Name");
        }
        else if(ui->teamSortRadio->isChecked()){
            team_stadiums.DisplayNational(ui->tableWidget);
            ui->tableTitleLabel->setText("List of National Stadium Information by Team Name");
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
        else if(ui->teamSortRadio->isChecked()){
            team_stadiums.DisplayAmerican(ui->tableWidget);
            ui->tableTitleLabel->setText("List of American Stadium Information by Team Name");
        }
        else{
            stadiums.DisplayAmerican(ui->tableWidget);
            ui->tableTitleLabel->setText("List of American Stadium Information by Date");
            }
    }

    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
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

void MainWindow::addNewStadium()
{
    std::string temp, team, stadium, state, phone, address;
    int cap, month, day, year;
    bool grass, league;
    if(ui->teamLine->text().isEmpty()||
            ui->nameLine->text().isEmpty()||
            ui->stateLine->text().isEmpty()||
            ui->phoneLine->text().isEmpty()||
            ui->addressLine->text().isEmpty()
            ){
        displayMsgBox("Please enter information into all fields.");
        return;
    }
    team = (ui->teamLine->text()).toStdString();
    stadium = ui->nameLine->text().toStdString();
    state = ui->stateLine->text().toStdString();
    phone = ui->phoneLine->text().toStdString();
    address = ui->addressLine->text().toStdString();
    if (ui->capLine->text().toInt() > 0)
        cap = ui->capLine->text().toInt();
    else{
        displayMsgBox("Please enter a valid capacity.");
        return;
    }

    if (ui->monthLine->text().toInt() > 0 &&  ui->monthLine->text().toInt() < 13)
        month = ui->monthLine->text().toInt();
    else{
        displayMsgBox("Please enter a valid month.");
        return;
    }

    if ( ui->dayLine->text().toInt() > 0 &&  ui->dayLine->text().toInt() < 32)
        day = ui->dayLine->text().toInt();
    else{
        displayMsgBox("Please enter a valid day.");
        return;
    }
    if ( ui->yearLine->text().toInt() > 1800 &&  ui->yearLine->text().toInt() < 2017)
        year = ui->dayLine->text().toInt();
    else{
        displayMsgBox("Please enter a valid year.");
        return;
    }

    if (ui->isGrassRadio->isChecked())
        grass = true;
    else
        grass = false;

    if (ui->isAmericanRadio->isChecked())
        league = 1;
    else
        league = 0;

    stadiums.insertNode(Stadium(team, stadium, address, state, phone, Date(month,day,year),
                            cap, league, grass));
    date_stadiums.insertNode(Stadium(team, stadium, address, state, phone, Date(month,day,year),
                            cap, league, grass));
    team_stadiums.insertNode(Stadium(team, stadium, address, state, phone, Date(month,day,year),
                                     cap, league, grass));
}

void MainWindow::setAdminMode()
{
    displayMsgBox("Welcome Administrator.");
    ui->tabWidget->setTabEnabled(3,true);
}

void MainWindow::setUserMode()
{
    displayMsgBox("Welcome User.");
    ui->tabWidget->setCurrentIndex(0);
    ui->tabWidget->setTabEnabled(3,false);
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
