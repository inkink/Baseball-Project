#ifndef SOUVENIR_H
#define SOUVENIR_H
#include "iostream"
using namespace std;

class Souvenir
{
public:
    Souvenir();
    Souvenir(string name="", double cost=0,int num=0);
    string getItem();
    double getPrice();
    int getQuantity();

private:
    string Item;
    double Price;
    int Quantity;
};

#endif // SOUVENIR_H
