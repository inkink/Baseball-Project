#include "stadiumtree.h"

/***********************************************************
 * FUNCTION DisplayTableInOrder O(nlogn)
 * ________________________________________________________
 * PRE-CONDITIONS
 * table - table to display to
 *
 * POST-CONDITIONS
 * The function will display contents in the table
 * *******************************************************/
void StadiumTree::DisplayTableInOrder(QTableWidget *table)
{
    inorderHelper(table, this->root, 0);
}

/***********************************************************
 * FUNCTION DisplayNational O(nlogn)
 * ________________________________________________________
 * PRE-CONDITIONS
 * table - table to display to
 *
 * POST-CONDITIONS
 * The function will display national stadiums'
 * contents in the table
 * *******************************************************/
void StadiumTree::DisplayNational(QTableWidget *table)
{
    inorderHelper(table, this->root, 1);
}

/***********************************************************
 * FUNCTION DisplayAmerican O(nlogn)
 * ________________________________________________________
 * PRE-CONDITIONS
 * table - table to display to
 *
 * POST-CONDITIONS
 * The function will display american stadiums'
 * contents in the table
 * *******************************************************/
void StadiumTree::DisplayAmerican(QTableWidget *table)
{
    inorderHelper(table, this->root, 2);
}

/***********************************************************
 * FUNCTION getStart O(logn)
 * ________________________________________________________
 * PRE-CONDITIONS
 * points - list of stadiums to go to
 *
 * POST-CONDITIONS
 * The function will get the stadiums from california
 * and store it in a vector
 * *******************************************************/
void StadiumTree::getStart(vector<Stadium> &points)
{
    getCAStadiums(root,points);
}

/***********************************************************
 * FUNCTION getCAStadiums O(logn)
 * ________________________________________________________
 * PRE-CONDITIONS
 * nodePtr - pointer to node in tree
 * trip    - list of stadiums in trip
 *
 * POST-CONDITIONS
 * The function will get the stadiums from california
 * and store it in a vector
 * *******************************************************/
void StadiumTree::getCAStadiums(TreeNode<Stadium,StadiumNameComparator> *nodePtr, vector<Stadium> &trip)
{
    if (nodePtr){
        getCAStadiums(nodePtr->left,trip);
        if (nodePtr->value.getState() == "CA"){
            trip.push_back(nodePtr->value);
        }
        getCAStadiums(nodePtr->right, trip);
    }
}

/***********************************************************
 * FUNCTION inorderHelper O(nlogn)
 * ________________________________________________________
 * PRE-CONDITIONS
 * table   - table to display to
 * nodePtr - pointer to node of tree
 * type    - type of league
 *
 * POST-CONDITIONS
 * The function will display american stadiums'
 * contents in the table
 * *******************************************************/
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

/***********************************************************
 * FUNCTION appendToTable O(1)
 * ________________________________________________________
 * PRE-CONDITIONS
 * table   - table to display to
 * stadium - stadium to append
 *
 * POST-CONDITIONS
 * The function will append the stadium to the table
 * *******************************************************/
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


