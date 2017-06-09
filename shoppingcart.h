#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H
#include <vector>
#include "souvenir.h"

class ShoppingCart
{
public:
    ShoppingCart();                             //constructor
    void buyItem(Souvenir item, int quantity);  //buys item
    string displayCart();                       //display cart info
private:
    vector<Souvenir> purchaseList;              //list of items purchased
    vector<int> quantityList;                   //list of item quantities
    double grandTotal;                          //total cost of cart
};

#endif // SHOPPINGCART_H
