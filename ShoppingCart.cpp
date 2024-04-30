/* Type your code here */
#include <iostream>
using namespace std;

#include "ShopingCart.h"

ShoppingCart::ShoppingCart(string customerName, string customerDate){
    this->customerName = customerName;
    this->currentDate = customerDate;
}

string ShoppingCart::GetCustomerName(){
    return customerName;
}
string ShoppingCart::GetDate(){
    return currentDate;
}
void ShoppingCart::AddItem(ItemToPurchase item){
    cartItems.push_back(item);
}
void ShoppingCart::RemoveItem(ItemToPurchase item){
    
}
