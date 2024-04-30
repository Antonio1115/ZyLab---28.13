/* Type your code here */

#ifndef SHOPPING_CART_H
#define SHOPPING_CART_H

#include <string>
#include <vector>
#include "ItemToPurchase.h"
using namespace std;

class ShoppingCart{

public:

ShoppingCart(string customerName = "none", string customerDate = "January 1, 2016");

string GetCustomerName();
string GetDate();

void AddItem(ItemToPurchase item);
void RemoveItem(ItemToPurchase item);
void ModifyItem(ItemToPurchase item);

void GetNumItemsInCart();
int GetCostOfCart();

void PrintTotal();
void PrintDescriptions();




private:

    string customerName;
    string currentDate;
    vector<ItemToPurchase> cartItems;

};

#endif