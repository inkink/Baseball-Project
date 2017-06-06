#include "souvenir.h"

Souvenir::Souvenir(string source, string Name, double cost){
    item = Name;
    price = cost;
    origin = source;
}

string Souvenir::getItem(){
    return item;
}

double Souvenir::getPrice(){
    return price;
}

string Souvenir::getOriginName(){
    return origin;
}

void Souvenir::setItem(string n){
    item = n;
}

void Souvenir::setPrice(double p){
    price = p;
}

bool Souvenir::operator==(Souvenir& other) const
{
    return other.getItem() == item;
}
