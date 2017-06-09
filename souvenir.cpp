#include "souvenir.h"

/***********************************************************
 * CONSTRUCTOR O(1)
 * ________________________________________________________
 * PRE-CONDITIONS
 * source - stadium souvenir sold from
 * name   - name of souvenir
 * cost   - cost of souvenir
 *
 * POST-CONDITIONS
 * The constructor creates a souvenir to store the origin
 * of purchase, name of item, and cost of item
 * *******************************************************/
Souvenir::Souvenir(string source, string Name, double cost){
    item = Name;
    price = cost;
    origin = source;
}

/***********************************************************
 * FUNCTION getItem O(1)
 * ________________________________________________________
 * PRE-CONDITIONS
 * none
 *
 * POST-CONDITIONS
 * The function will return the item name
 * *******************************************************/
string Souvenir::getItem(){
    return item;
}

/***********************************************************
 * FUNCTION getPrice O(1)
 * ________________________________________________________
 * PRE-CONDITIONS
 * none
 *
 * POST-CONDITIONS
 * The function will return the item price
 * *******************************************************/
double Souvenir::getPrice(){
    return price;
}

/***********************************************************
 * FUNCTION getOrigin O(1)
 * ________________________________________________________
 * PRE-CONDITIONS
 * none
 *
 * POST-CONDITIONS
 * The function will return the item origin
 * *******************************************************/
string Souvenir::getOriginName(){
    return origin;
}

/***********************************************************
 * FUNCTION setItem O(1)
 * ________________________________________________________
 * PRE-CONDITIONS
 * n - new name
 *
 * POST-CONDITIONS
 * The function will assign a new item name
 * *******************************************************/
void Souvenir::setItem(string n){
    item = n;
}

/***********************************************************
 * FUNCTION setPrice O(1)
 * ________________________________________________________
 * PRE-CONDITIONS
 * p - new price
 *
 * POST-CONDITIONS
 * The function will assign a new item price
 * *******************************************************/
void Souvenir::setPrice(double p){
    price = p;
}

/***********************************************************
 * FUNCTION setItem O(1)
 * ________________________________________________________
 * PRE-CONDITIONS
 * other - other souvenir to check
 *
 * POST-CONDITIONS
 * The function will return true if souvenir names match
 * *******************************************************/
bool Souvenir::operator==(Souvenir& other) const
{
    return other.getItem() == item;
}
