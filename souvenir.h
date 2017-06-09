#ifndef SOUVENIR_H
#define SOUVENIR_H
#include <iostream>
using namespace std;

class Souvenir
{
public:
    Souvenir(string source, string Name="", double cost=0); //constructor
    string getItem();                                       //returns item name
    double getPrice();                                      //returns item cost
    string getOriginName();                                 //returns item origin
    void setItem(string n);                                 //assign new name
    void setPrice(double p);                                //assign new price
    bool operator==(Souvenir& other) const;                 //overloaded==

private:
    string item;                                            //item name
    double price;                                           //item price
    string origin;                                          //stadium of origin
};

#endif // SOUVENIR_H
