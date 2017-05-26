#include "stadiumtree.h"



template<typename C>
void StadiumTree<C>::DisplayTableInOrder(QTableWidget *table)
{
    inorderHelper(table, this->root);
}


template<typename C>
void StadiumTree<C>::inorderHelper(QTableWidget *table, TreeNode<Stadium, C> *nodePtr)
{
    if(nodePtr){
        inorderHelper(table,nodePtr->left);
        appendToTable(table, nodePtr->value);
        inorderHelper(table,nodePtr->right);
    }
}

template<typename C>
void StadiumTree<C>::appendToTable(QTableWidget *table, Stadium stadium)
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
        table->setItem(n,4,new QTableWidgetItem("Grass"));
    else
        table->setItem(n,4,new QTableWidgetItem("Other"));

    if (stadium.getLeague())
        table->setItem(n,4,new QTableWidgetItem("American"));
    else
        table->setItem(n,4,new QTableWidgetItem("National"));
}


