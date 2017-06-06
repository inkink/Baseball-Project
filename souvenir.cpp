#include "souvenir.h"

Souvenir::Souvenir(Stadium s, string Name, double cost){
    item = Name;
    price = cost;
    origin = s;
}

string Souvenir::getItem(){
    return item;
}

double Souvenir::getPrice(){
    return price;
}

string Souvenir::getOriginName(){
    return origin.getStadiumName();
}

void Souvenir::setItem(string n){
    item = n;
}

void Souvenir::setPrice(double p){
    price = p;
}
