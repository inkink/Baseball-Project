#ifndef STADIUMDATETREE_H
#define STADIUMDATETREE_H
#include "binarytree.h"
#include "stadium.h"
#include <QTableWidget>


class StadiumDateTree :
        public BinaryTree<Stadium, StadiumDateComparator>
{
public:

    void DisplayTableInOrder(QTableWidget *table);                  //display tree in table
    void DisplayNational(QTableWidget *table);                      //display national stadiums
    void DisplayAmerican(QTableWidget *table);                      //display american stadiums

private:
    void inorderHelper(QTableWidget *table, TreeNode<Stadium,
                       StadiumDateComparator> *nodePtr, int type);  //helps keep order
    void appendToTable(QTableWidget *table, Stadium stadium);       //add to table

};



#endif // STADIUMDATETREE_H
