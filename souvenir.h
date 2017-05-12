#ifndef SOUVENIR_H
#define SOUVENIR_H
#include "iostream"
using namespace std;

class Souvenir
{
public:
//    Souvenir();
    Souvenir(string Name="", double cost=0,int num=0);
    string getItem();
    double getPrice();
    int getQuantity();

    void setItem(string n);
    void setPrice(double p);
    void setQuantity(int n);

private:
    string item;
    double price;
    int quantity;
};

#endif // SOUVENIR_H
