#include "shoppingcart.h"

ShoppingCart::ShoppingCart()
{
    purchaseList.reserve(50);
    quantityList.reserve(50);
    grandTotal = 0;
}

void ShoppingCart::buyItem(Souvenir item, int quantity)
{
    purchaseList.push_back(item);
    quantityList.push_back(quantity);
    grandTotal += item.getPrice() * quantity;
}

string ShoppingCart::displayCart()
{
    string result = "Shopping Cart:\n";
    string temp;
    for(int i=0; i<purchaseList.size(); i++)
    {
        result += "- " + purchaseList[i].getItem()
                + ",   " + to_string(purchaseList[i].getPrice())
                + ",   " + to_string(quantityList[i])
                + ",   " + purchaseList[i].getOriginName() + "\n";
    }
    result += "\nGrand Total: " + to_string(grandTotal);
    return result;
}
