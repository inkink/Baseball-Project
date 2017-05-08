#include "souvenir.h"

Souvenir::Souvenir(string Name="", double cost=0,int num=0){
    Item = Name;
    Price = cost;
    Quantity = num;
}

string Souvenir::getItem(){
    return Item;
}

double Souvenir::getPrice(){
    return Price;
}

int Souvenir::getQuantity(){
    return Quantity;
}
