#ifndef SOUVENIR_H
#define SOUVENIR_H
#include <iostream>
#include "stadium.h"
using namespace std;

class Souvenir
{
public:
    Souvenir(Stadium s, string Name="", double cost=0);
    string getItem();
    double getPrice();
    string getOriginName();

    void setItem(string n);
    void setPrice(double p);

private:
    string item;
    double price;
    Stadium origin;
};

#endif // SOUVENIR_H
