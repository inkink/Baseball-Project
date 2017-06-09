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
    void DisplayNational(QTableWidget *table);
    void DisplayAmerican(QTableWidget *table);
    void DisplayGrass (QTableWidget *table);
    void test();
    void getStart(vector<Stadium>& points);
    Stadium getStadium(string stadium);


private:
    void getCAStadiums(TreeNode<Stadium,StadiumNameComparator> *nodePtr, vector<Stadium>& trip);
    void inorderHelper(QTableWidget *table, TreeNode<Stadium, StadiumNameComparator> *nodePtr, int type);
    void appendToTable(QTableWidget *table, Stadium stadium);
    Stadium getStadiumHelper(string stadium, TreeNode<Stadium, StadiumNameComparator> *nodePtr);

};



#endif // STADIUMTREE_H
