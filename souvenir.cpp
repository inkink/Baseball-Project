#include "souvenir.h"

//Souvenir::Souvenir(){
//    Item = "";
//    Price = 0.0;
//    Quantity = 0;
//}

Souvenir::Souvenir(string Name, double cost,int num){
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
