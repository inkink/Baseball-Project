#ifndef STADIUMTEAMTREE_H
#define STADIUMTEAMTREE_H
#include "binarytree.h"
#include "stadium.h"
#include <QTableWidget>

class StadiumTeamTree :
        public BinaryTree<Stadium, TeamNameComparator>
{
public:
    void DisplayTableInOrder(QTableWidget *table);              //display tree in table
    void DisplayNational(QTableWidget *table);                  //display national stadiums
    void DisplayAmerican(QTableWidget *table);                  //display american stadiums

private:
    void inorderHelper(QTableWidget *table, TreeNode<Stadium,
                       TeamNameComparator> *nodePtr, int type); //helps keep order
    void appendToTable(QTableWidget *table, Stadium stadium);   //add to table

};

#endif // STADIUMTEAMTREE_H
