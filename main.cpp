#include <iostream>
#include "binarytree.h"
#include "date.h"
#include "stadium.h"
#include "souvenir.h"
#include "address.h"
using namespace std;

int main()
{
//    cout << "Hello World!" << endl;
//    BinaryTree<int> tree;
//    int num1 = 2;
//    tree.insertNode(num1);
//    tree.insertNode(23);
//    tree.displayInOrder();
    Address one("address","city","STATE",123456);
    Date date(10,12,1908);
//    cout<<date<<endl;
//    string team, string address, string phone, Date date, int cap
    Stadium gym("Team NAME",one,"phone",date,0);
    cout<<gym<<endl;

//    Stadium gym1("abc",one,"phone",date,0);
//    cout<<(gym>gym1)<<endl;


//    cout<<one;
    return 0;
}

