#ifndef STADIUMTREE_H
#define STADIUMTREE_H
#include "binarytree.h"
#include "stadium.h"
#include <QTableWidget>


class StadiumTree :
        public BinaryTree<Stadium, StadiumNameComparator>
{
public:

    void DisplayTableInOrder(QTableWidget *table);
    void test();

private:
    void inorderHelper(QTableWidget *table, TreeNode<Stadium, StadiumNameComparator> *nodePtr);
    void appendToTable(QTableWidget *table, Stadium stadium);

};



#endif // STADIUMTREE_H
