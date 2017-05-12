#include "souvenir.h"

Souvenir::Souvenir(string Name, double cost,int num){
    item = Name;
    price = cost;
    quantity = num;
}

string Souvenir::getItem(){
    return item;
}

double Souvenir::getPrice(){
    return price;
}

int Souvenir::getQuantity(){
    return quantity;
}

void Souvenir::setItem(string n){
    item = n;
}

void Souvenir::setPrice(double p){
    price = p;
}

void Souvenir::setQuantity(int n){
    quantity = n;
}
