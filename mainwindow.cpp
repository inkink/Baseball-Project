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

    //test for souvenir
    current = stadiums.getRoot();
    //set tab, disable admin tab
    ui->tabWidget->setCurrentIndex(0);
    ui->tabWidget->setTabEnabled(3,false);
    ui->addItemBtn->setEnabled(false);
    ui->modifyItemBtn->setEnabled(false);
    ui->removeItemBtn->setEnabled(false);
    showStartingPoints();

    all_stadiums = {"SafeCo Field", "AT&T Park", "O.co Coliseum",
                     "Dodger Stadium", "Angels Stadium of Anaheim", "PETCO Park",
                     "Chase Field", "Coer's Field","Rangers Ballpark",
                     "Minute Maid Park", "Kauffman Stadium", "Busch Stadium",
                     "Target Field", "Miller Park", "Wrigley Field", "US Cellular Field",
                     "Comerica Park", "Progressive Field", "Great American Ball Park",
                     "PNC Park", "Rogers Center", "Fenway Park", "Yankee Stadium",
                     "Citi Field","Citizens Bank",
                     "Nationals Park","Oriole Park at Camden Yards",
                        "Turner Field", "Tropicano Field", "Marlin's Park"};

    for (int i = 0; i < all_stadiums.size(); i++){
        ui->souvenierCombo->addItem(QString::fromStdString(all_stadiums[i]));
        ui->distance1Combo->addItem(QString::fromStdString(all_stadiums[i]));
        ui->distance2Combo->addItem(QString::fromStdString(all_stadiums[i]));
    }
}

//destructor
MainWindow::~MainWindow()
{
    delete ui;
}

//load the information from the file into the
//trees
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
    ui->tableWidget->setColumnWidth(0,200);
    ui->tableWidget->setColumnWidth(1,200);
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
    else if (ui->grassRadio->isChecked()){
        if (ui->dateSortRadio->isChecked()){
            date_stadiums.DisplayGrass(ui->tableWidget);
            ui->tableTitleLabel->setText("List of American Stadium Information by Name");
        }
        else if(ui->teamSortRadio->isChecked()){
            team_stadiums.DisplayGrass(ui->tableWidget);
            ui->tableTitleLabel->setText("List of American Stadium Information by Team Name");
        }
        else{
            stadiums.DisplayGrass(ui->tableWidget);
            ui->tableTitleLabel->setText("List of American Stadium Information by Date");
            }
    }
}

void MainWindow::listSouvenir()
{
    cout << current.displaySouvenir() << endl;
    QString qstr = QString::fromStdString(current.displaySouvenir());
    ui->itemDisplay->setText(qstr);
}

void MainWindow::buySouvenir()
{
    if (!ui->itemQuantityEdit->text().isEmpty()){
        string itemName = ui->itemNameEdit->text().toStdString();
        int itemQuantity = ui->itemQuantityEdit->text().toInt();
        if(current.findSouvenir(itemName))
        {
            Souvenir temp = current.getSouvenir(itemName);
            cout << temp.getItem() << " " << temp.getOriginName() << " " << temp.getPrice() << endl;
            cart.buyItem(temp, itemQuantity);
        }
    }
}

void MainWindow::addSouvenir()
{
    if (!ui->newNameEdit->text().isEmpty() && !ui->newPriceEdit->text().isEmpty()){
        string itemName = ui->newNameEdit->text().toStdString();
        double itemPrice = ui->newPriceEdit->text().toDouble();
        current.addSouvenir(itemName, itemPrice);
    }
}

void MainWindow::removeSouvenir()
{
    if (!ui->newNameEdit->text().isEmpty()){
        string itemName = ui->itemNameEdit->text().toStdString();
        if(current.findSouvenir(itemName))
        {
            current.removeSouvenir(itemName);
        }
    }
}

void MainWindow::modifySouvenir()
{
    if (!ui->newNameEdit->text().isEmpty() && !ui->newPriceEdit->text().isEmpty()){
        string oldName = ui->itemNameEdit->text().toStdString();
        if(current.findSouvenir(oldName))
        {
            string newName = ui->newNameEdit->text().toStdString();
            double newCost = ui->newPriceEdit->text().toDouble();
            current.modifySouvenir(oldName, newName, newCost);
        }
    }
}

void MainWindow::displayCart()
{
    cout << cart.displayCart() << endl;
    QString qstr = QString::fromStdString(cart.displayCart());
    ui->itemDisplay->setText(qstr);
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

void MainWindow::showStartingPoints()
{
    ui->startStadiumCombo->clear();
    vector<std::string> starting;
    if (ui->tripAllRadio->isChecked()){
        starting = {"AT&T Park", "O.co Coliseum",
                                    "Dodger Stadium","Angels Stadium of Anaheim", "PETCO Park"};}
    else if (ui->tripAmericanRadio->isChecked()){
        starting = {"O.co Coliseum","Angels Stadium of Anaheim"};
    }
    else{
        starting = {"AT&T Park", "Dodger Stadium", "PETCO Park"};
    }

    for (int i = 0; i < starting.size(); i++)
        ui->startStadiumCombo->addItem(QString::fromStdString(starting[i]));
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
        year = ui->yearLine->text().toInt();
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
    ui->addItemBtn->setEnabled(true);
    ui->modifyItemBtn->setEnabled(true);
    ui->removeItemBtn->setEnabled(true);
}

void MainWindow::setUserMode()
{
    displayMsgBox("Welcome User.");
    ui->tabWidget->setCurrentIndex(0);
    ui->tabWidget->setTabEnabled(3,false);
    ui->addItemBtn->setEnabled(false);
    ui->modifyItemBtn->setEnabled(false);
    ui->removeItemBtn->setEnabled(false);
}

void MainWindow::createNewTrip()
{
    vector<string> stadiums {"SafeCo Field","AT&T Park","Dodger Stadium","PETCO Park",
                     "Chase Field","Coer's Field","Rangers Ballpark",
                     "Minute Maid Park", "Kauffman Stadium", "Busch Stadium",
                     "Target Field", "Miller Park", "Wrigley Field",
                     "Comerica Park", "Progressive Field", "Great America Ball Park",
                     "PNC Park", "Rogers Center", "Fenway Park", "Yankee Stadium",
                     "Citizens Bank", "Nationals Park", "Turner Field",
                     "Tropicano Field", "Marlin's Park"};

    if (ui->startStadiumCombo->currentIndex() != -1)
        if (ui->autoTripButton->isChecked()){
            string start = ui->startStadiumCombo->currentText().toStdString();
            if (ui->tripAllRadio->isChecked()){
                const int v = 25;
                int** grapha=new int* [v];
                int** walker= grapha;
                for(int i=0;i<v;i++){
                    *walker=new int[v];
                    walker++;
                }
                int graphb[v][v]={{0,680,0,0,0,0,0,0,0,0,1390,0,0,0,0,0,0,2070,0,0,0,0,0,0,0},
                                               {680,0,340,0,650,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                               {0,340,0,110,0,0,0,0,0,0,1500,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                               {0,0,110,0,400,830,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                               {0,650,0,400,0,580,870,1115,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                               {0,0,0,830,580,0,650,0,560,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                               {0,0,0,0,870,650,0,230,460,0,0,0,0,0,0,0,0,0,0,0,0,0,740,0,0},
                                               {0,0,0,0,1115,0,230,0,0,680,0,0,0,0,0,0,0,0,0,0,0,0,0,790,965},
                                               {0,0,0,0,0,560,460,0,0,235,0,0,415,0,0,0,0,0,0,0,0,0,0,0,0},
                                               {0,0,0,0,0,0,0,680,235,0,465,0,0,0,0,310,0,0,0,0,0,0,0,0,0},
                                               {1390,0,1500,0,0,0,0,0,0,465,0,300,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                               {0,0,0,0,0,0,0,0,0,0,300,0,80,0,0,0,0,430,0,0,0,0,0,0,0},
                                               {0,0,0,0,0,0,0,0,415,0,0,80,0,240,0,250,0,0,0,0,0,0,0,0,0},
                                               {0,0,0,0,0,0,0,0,0,0,0,0,240,0,90,0,0,430,0,0,0,0,0,0,0},
                                               {0,0,0,0,0,0,0,0,0,0,0,0,0,90,0,225,115,0,0,0,0,0,0,0,0},
                                               {0,0,0,0,0,0,0,0,0,310,0,0,250,0,225,0,260,0,0,0,0,0,375,790,0},
                                               {0,0,0,0,0,0,0,0,0,0,0,0,0,0,115,260,0,225,315,0,0,90,0,0,0},
                                               {2070,0,0,0,0,0,0,0,0,0,0,430,0,430,0,0,225,0,430,0,0,0,0,0,0},
                                               {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,315,430,0,195,0,0,0,0,1255},
                                               {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,195,0,80,0,0,0,0},
                                               {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,80,0,90,0,0,0},
                                               {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,90,0,0,0,90,0,560,0,930},
                                               {0,0,0,0,0,0,740,0,0,0,0,0,0,0,0,375,0,0,0,0,0,560,0,0,600},
                                               {0,0,0,0,0,0,0,790,0,0,0,0,0,0,0,790,0,0,0,0,0,0,0,0,210},
                                               {0,0,0,0,0,0,0,965,0,0,0,0,0,0,0,0,0,0,1255,0,0,930,600,210,0}};
                for(int i=0;i<v;i++){
                    for(int j=0;j<v;j++)
                        grapha[i][j]=graphb[i][j];
                }
                graph test(grapha,25);
                std::vector<int> trip;
                tripLength = test.findShortestForAllB(ui->startStadiumCombo->currentIndex()+1,trip);
                clearTable();
                ui->stadiumsCombo->clear();
                allTrip.clear();
                ui->tableWidget->setColumnCount(1);
                ui->tableWidget->setColumnWidth(0,200);
                for (int i = 0; i < trip.size(); i++){
                    ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);
                    ui->tableWidget->setItem(i,0,new QTableWidgetItem( QString::fromStdString(all_stadiums[trip[i]])));
                }
                ui->tripLengthLabel->setText(QString::number(tripLength));
            }
        }
        else{
            clearTable();
            ui->stadiumsCombo->clear();
            string start_stadium = ui->startStadiumCombo->currentText().toStdString();
            vector<int> trip;
            ui->tableWidget->setColumnCount(1);
            ui->tableWidget->setColumnWidth(0,200);
            ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);
            ui->tableWidget->setItem(0,0,new QTableWidgetItem( QString::fromStdString(start_stadium)));
            for (int i = 0; i < all_stadiums.size(); i++){
                if (start_stadium != all_stadiums[i])
                    ui->stadiumsCombo->addItem(QString::fromStdString(all_stadiums[i]));
            }
            ui->tripLengthLabel->setText("0");
            currentIndex = 1;
            tripLength = 0;
        }
}

void MainWindow::updateVisit()
{
    showStartingPoints();
}

void MainWindow::addToTrip()
{
    int graph[25][25]={{0,680,0,0,0,0,0,0,0,0,1390,0,0,0,0,0,0,2070,0,0,0,0,0,0,0},
                                   {680,0,340,0,650,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                   {0,340,0,110,0,0,0,0,0,0,1500,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                   {0,0,110,0,400,830,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                   {0,650,0,400,0,580,870,1115,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                   {0,0,0,830,580,0,650,0,560,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                   {0,0,0,0,870,650,0,230,460,0,0,0,0,0,0,0,0,0,0,0,0,0,740,0,0},
                                   {0,0,0,0,1115,0,230,0,0,680,0,0,0,0,0,0,0,0,0,0,0,0,0,790,965},
                                   {0,0,0,0,0,560,460,0,0,235,0,0,415,0,0,0,0,0,0,0,0,0,0,0,0},
                                   {0,0,0,0,0,0,0,680,235,0,465,0,0,0,0,310,0,0,0,0,0,0,0,0,0},
                                   {1390,0,1500,0,0,0,0,0,0,465,0,300,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                   {0,0,0,0,0,0,0,0,0,0,300,0,80,0,0,0,0,430,0,0,0,0,0,0,0},
                                   {0,0,0,0,0,0,0,0,415,0,0,80,0,240,0,250,0,0,0,0,0,0,0,0,0},
                                   {0,0,0,0,0,0,0,0,0,0,0,0,240,0,90,0,0,430,0,0,0,0,0,0,0},
                                   {0,0,0,0,0,0,0,0,0,0,0,0,0,90,0,225,115,0,0,0,0,0,0,0,0},
                                   {0,0,0,0,0,0,0,0,0,310,0,0,250,0,225,0,260,0,0,0,0,0,375,790,0},
                                   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,115,260,0,225,315,0,0,90,0,0,0},
                                   {2070,0,0,0,0,0,0,0,0,0,0,430,0,430,0,0,225,0,430,0,0,0,0,0,0},
                                   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,315,430,0,195,0,0,0,0,1255},
                                   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,195,0,80,0,0,0,0},
                                   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,80,0,90,0,0,0},
                                   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,90,0,0,0,90,0,560,0,930},
                                   {0,0,0,0,0,0,740,0,0,0,0,0,0,0,0,375,0,0,0,0,0,560,0,0,600},
                                   {0,0,0,0,0,0,0,790,0,0,0,0,0,0,0,790,0,0,0,0,0,0,0,0,210},
                                   {0,0,0,0,0,0,0,965,0,0,0,0,0,0,0,0,0,0,1255,0,0,930,600,210,0}};

    if (ui->stadiumsCombo->count() > 0){
        int index;
        for (int i = 0; i < all_stadiums.size(); i++){
            if (all_stadiums[i] == ui->stadiumsCombo->currentText().toStdString()){
                index = i;
            }
        }
        if (index > 1)
            --index;
        if (index > 3) --index;
        if (index > 14) --index;
        if (index > 22) --index;
        if (index > 25) --index;
        prevIndex = currentIndex;
        currentIndex = index;
        tripLength += graph[prevIndex][currentIndex];
        ui->tripLengthLabel->setText(QString::number(tripLength));
        ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,0,new QTableWidgetItem(ui->stadiumsCombo->currentText()));
        ui->stadiumsCombo->removeItem(ui->stadiumsCombo->currentIndex());
    }
    else{
        displayMsgBox("You have visited every stadium!");
    }
}

void MainWindow::updateCurrent()
{
  //  if (ui->souvenierCombo->count() > 0)
   //     current = stadiums.getStadium(ui->souvenierCombo->currentText().toStdString());
    listSouvenir();
}

void MainWindow::getShortestPath()
{
    int** grapha=new int* [25];
    int** walker= grapha;
    for(int i=0;i<25;i++){
        *walker=new int[25];
        walker++;
    }
    int graphb[25][25]={{0,680,0,0,0,0,0,0,0,0,1390,0,0,0,0,0,0,2070,0,0,0,0,0,0,0},
                                   {680,0,340,0,650,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                   {0,340,0,110,0,0,0,0,0,0,1500,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                   {0,0,110,0,400,830,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                   {0,650,0,400,0,580,870,1115,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                   {0,0,0,830,580,0,650,0,560,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                   {0,0,0,0,870,650,0,230,460,0,0,0,0,0,0,0,0,0,0,0,0,0,740,0,0},
                                   {0,0,0,0,1115,0,230,0,0,680,0,0,0,0,0,0,0,0,0,0,0,0,0,790,965},
                                   {0,0,0,0,0,560,460,0,0,235,0,0,415,0,0,0,0,0,0,0,0,0,0,0,0},
                                   {0,0,0,0,0,0,0,680,235,0,465,0,0,0,0,310,0,0,0,0,0,0,0,0,0},
                                   {1390,0,1500,0,0,0,0,0,0,465,0,300,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                   {0,0,0,0,0,0,0,0,0,0,300,0,80,0,0,0,0,430,0,0,0,0,0,0,0},
                                   {0,0,0,0,0,0,0,0,415,0,0,80,0,240,0,250,0,0,0,0,0,0,0,0,0},
                                   {0,0,0,0,0,0,0,0,0,0,0,0,240,0,90,0,0,430,0,0,0,0,0,0,0},
                                   {0,0,0,0,0,0,0,0,0,0,0,0,0,90,0,225,115,0,0,0,0,0,0,0,0},
                                   {0,0,0,0,0,0,0,0,0,310,0,0,250,0,225,0,260,0,0,0,0,0,375,790,0},
                                   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,115,260,0,225,315,0,0,90,0,0,0},
                                   {2070,0,0,0,0,0,0,0,0,0,0,430,0,430,0,0,225,0,430,0,0,0,0,0,0},
                                   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,315,430,0,195,0,0,0,0,1255},
                                   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,195,0,80,0,0,0,0},
                                   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,80,0,90,0,0,0},
                                   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,90,0,0,0,90,0,560,0,930},
                                   {0,0,0,0,0,0,740,0,0,0,0,0,0,0,0,375,0,0,0,0,0,560,0,0,600},
                                   {0,0,0,0,0,0,0,790,0,0,0,0,0,0,0,790,0,0,0,0,0,0,0,0,210},
                                   {0,0,0,0,0,0,0,965,0,0,0,0,0,0,0,0,0,0,1255,0,0,930,600,210,0}};
    for(int i=0;i<25;i++){
        for(int j=0;j<25;j++)
            grapha[i][j]=graphb[i][j];
    }
    graph test(grapha,25);
    int index = ui->distance1Combo->currentIndex();
    int index2 = ui->distance2Combo->currentIndex();
    if (index > 1) --index;
    if (index > 3) --index;
    if (index > 14) --index;
    if (index > 22) --index;
    if (index > 25) --index;
    if (index2 > 1) --index2;
    if (index2 > 3) --index2;
    if (index2 > 14) --index2;
    if (index2 > 22) --index2;
    if (index2 > 25) --index2;
    ui->distanceLabel->setText(QString::number(test.shortestPath(index,index2)));
}

