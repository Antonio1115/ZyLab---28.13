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
    auto findItem = find(cartItems.begin(),cartItems.end(), item);

    if(findItem != cartItems.end()){
        cartItems.erase(findItem);
    }else{
        cout << "Item not found in cart. Nothing removed." << endl;
    }
}
void ShoppingCart::ModifyItem(ItemToPurchase item){

    auto findItem = find(cartItems.begin(),cartItems.end(), item);

    if(findItem != cartItems.end()){
        if(item.GetName() == "none"){
           
            // Figure out later

        }
    }else{
        cout << "Item not found in cart. Nothing modified." << endl;
    }

}
void ShoppingCart::GetNumItemsInCart(){
    cout << cartItems.size() << endl;
}
int ShoppingCart::GetCostOfCart(){

    int totalCost = 0;

    for(int i = 0; i < cartItems.size(); i ++){
        totalCost += cartItems.at(i).GetPrice();
    }
    return totalCost;
}