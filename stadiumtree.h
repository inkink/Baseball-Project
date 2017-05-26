#ifndef STADIUMTREE_H
#define STADIUMTREE_H
#include "binarytree.h"
#include "stadium.h"
#include <QTableWidget>


template<class C>
class StadiumTree :
        public BinaryTree<Stadium, C>
{
public:

    void DisplayTableInOrder(QTableWidget *table);

private:
    void inorderHelper(QTableWidget *table, TreeNode<Stadium, C> *nodePtr);
    void appendToTable(QTableWidget *table, Stadium stadium);

};



#endif // STADIUMTREE_H
