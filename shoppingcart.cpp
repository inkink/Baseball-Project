#include "shoppingcart.h"

/***********************************************************
 * CONSTRUCTOR O(1)
 * ________________________________________________________
 * PRE-CONDITIONS
 * none
 *
 * POST-CONDITIONS
 * The constructor creates a shopping cart to store all
 * of the souvenirs purchased
 * *******************************************************/
ShoppingCart::ShoppingCart()
{
    purchaseList.reserve(50);
    quantityList.reserve(50);
    grandTotal = 0;
}

/***********************************************************
 * FUNCTION buyItem O(1)
 * ________________________________________________________
 * PRE-CONDITIONS
 * item     - souvenir to buy
 * quantity - quantity to buy
 *
 * POST-CONDITIONS
 * The function will return if address is in california
 * *******************************************************/
void ShoppingCart::buyItem(Souvenir item, int quantity)
{
    purchaseList.push_back(item);
    quantityList.push_back(quantity);
    grandTotal += item.getPrice() * quantity;
}

/***********************************************************
 * FUNCTION displayCart O(n)
 * ________________________________________________________
 * PRE-CONDITIONS
 * none
 *
 * POST-CONDITIONS
 * The function will return a string of the contents of
 * the cart
 * *******************************************************/
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
