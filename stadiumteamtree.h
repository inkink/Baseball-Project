#ifndef STADIUMTEAMTREE_H
#define STADIUMTEAMTREE_H
#include "binarytree.h"
#include "stadium.h"
#include <QTableWidget>

class StadiumTeamTree :
        public BinaryTree<Stadium, TeamNameComparator>
{
public:
    void DisplayTableInOrder(QTableWidget *table);
    void DisplayNational(QTableWidget *table);
    void DisplayAmerican(QTableWidget *table);

private:
    void inorderHelper(QTableWidget *table, TreeNode<Stadium, TeamNameComparator> *nodePtr, int type);
    void appendToTable(QTableWidget *table, Stadium stadium);

};

#endif // STADIUMTEAMTREE_H
