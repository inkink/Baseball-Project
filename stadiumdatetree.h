#ifndef STADIUMDATETREE_H
#define STADIUMDATETREE_H
#include "binarytree.h"
#include "stadium.h"
#include <QTableWidget>


class StadiumDateTree :
        public BinaryTree<Stadium, StadiumDateComparator>
{
public:

    void DisplayTableInOrder(QTableWidget *table);
    void DisplayNational(QTableWidget *table);
    void DisplayAmerican(QTableWidget *table);
    void test();

private:
    void inorderHelper(QTableWidget *table, TreeNode<Stadium, StadiumDateComparator> *nodePtr, int type);
    void appendToTable(QTableWidget *table, Stadium stadium);

};



#endif // STADIUMDATETREE_H
