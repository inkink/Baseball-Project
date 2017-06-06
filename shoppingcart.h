#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H
#include <vector>
#include "souvenir.h"

class ShoppingCart
{
public:
    ShoppingCart();
    void buyItem(Souvenir item, int quantity);
    string displayCart();
private:
    vector<Souvenir> souvenirList;
    vector<Souvenir> purchaseList;
    vector<int> quantityList;
    double grandTotal;
};

#endif // SHOPPINGCART_H
