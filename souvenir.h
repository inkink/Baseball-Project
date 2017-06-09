#ifndef SOUVENIR_H
#define SOUVENIR_H
#include <iostream>
using namespace std;

class Souvenir
{
public:
    Souvenir(string source, string Name="", double cost=0);
    string getItem();
    double getPrice();
    string getOriginName();

    void setItem(string n);
    void setPrice(double p);

    bool operator==(Souvenir& other) const;

private:
    string item;
    double price;
    string origin;
};

#endif // SOUVENIR_H
