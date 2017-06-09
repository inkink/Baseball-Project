#ifndef STADIUMTREE_H
#define STADIUMTREE_H
#include "binarytree.h"
#include "stadium.h"
#include <QTableWidget>


class StadiumTree :
        public BinaryTree<Stadium, StadiumNameComparator>
{
public:

    void DisplayTableInOrder(QTableWidget *table);                  //display tree in table
    void DisplayNational(QTableWidget *table);                      //display national stadiums
    void DisplayAmerican(QTableWidget *table);                      //display american stadiums
    void getStart(vector<Stadium>& points);                         //get starting point

private:
    void getCAStadiums(TreeNode<Stadium,StadiumNameComparator>
                       *nodePtr, vector<Stadium>& trip);            //gets california stadiums
    void inorderHelper(QTableWidget *table, TreeNode<Stadium,
                       StadiumNameComparator> *nodePtr, int type);  //helps keep order
    void appendToTable(QTableWidget *table, Stadium stadium);       //add to table

};



#endif // STADIUMTREE_H
