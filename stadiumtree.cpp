#include "stadiumtree.h"



void StadiumTree::DisplayTableInOrder(QTableWidget *table)
{
    inorderHelper(table, this->root, 0);
}

void StadiumTree::DisplayNational(QTableWidget *table)
{
    inorderHelper(table, this->root, 1);
}

void StadiumTree::DisplayAmerican(QTableWidget *table)
{
    inorderHelper(table, this->root, 2);
}

void StadiumTree::test()
{
    cout << "hello" << endl;
}


void StadiumTree::inorderHelper(QTableWidget *table, TreeNode<Stadium, StadiumNameComparator> *nodePtr,int type)
{
    if(nodePtr){
        inorderHelper(table,nodePtr->left, type);
        if (type == 1 && !nodePtr->value.getLeague())
            appendToTable(table, nodePtr->value);
        else if (type == 2 && nodePtr->value.getLeague())
            appendToTable(table,nodePtr->value);
        else if (type == 0)
            appendToTable(table, nodePtr->value);
        inorderHelper(table,nodePtr->right, type);
    }
}

void StadiumTree::appendToTable(QTableWidget *table, Stadium stadium)
{
    table->setRowCount(table->rowCount()+1);
    int n = table->rowCount()-1;

    table->setItem(n,0,new QTableWidgetItem( QString::fromStdString(stadium.getStadiumName())));
    table->setItem(n,1,new QTableWidgetItem( QString::fromStdString(stadium.getTeamName())));

    table->setItem(n,2,new QTableWidgetItem( QString::fromStdString(stadium.getAddress())));
    table->setItem(n,3,new QTableWidgetItem( QString::fromStdString(stadium.getPhoneNum())));

    table->setItem(n,4,new QTableWidgetItem( QString::fromStdString(stadium.getOpenDate().getString())));
    table->setItem(n,5,new QTableWidgetItem( QString::number(stadium.getCapacity())));

    if (stadium.getGrass())
        table->setItem(n,6,new QTableWidgetItem("Grass"));
    else
        table->setItem(n,6,new QTableWidgetItem("Other"));

    if (stadium.getLeague())
        table->setItem(n,7,new QTableWidgetItem("American"));
    else
        table->setItem(n,7,new QTableWidgetItem("National"));
}



