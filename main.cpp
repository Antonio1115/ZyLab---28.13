#include <iostream>
#include <iomanip>
using namespace std;

#include "ShopingCart.h"

void PrintMenu() {
   cout << "MENU" << endl;
   cout << "a - Add item to cart" << endl;
   cout << "d - Remove item from cart" << endl;
   cout << "c - Change item quantity" << endl;
   cout << "i - Output items' descriptions" << endl;
   cout << "o - Output shopping cart" << endl;
   cout << "q - Quit" << endl;
}


void ExecuteMenu(char option, ShoppingCart& SC) {
   vector<ItemToPurchase> cartItems;
   if(option == 'o'){
      int cost = 0;
      cout << "OUTPUT SHOPPING CART" << endl;
      cout << SC.GetCustomerName() << "'s Shopping Cart - " << SC.GetDate() << endl;
      cout << "Number of Items: " << SC.GetNumItemsInCart() << endl;
      for(int i=0; i<SC.GetNumItemsInCart(); i++){
         cartItems[i].PrintItemCost();
         cout << endl;
      }
      for(int i=0; i<SC.GetNumItemsInCart(); i++){
        cost += cartItems[i].GetCost();
      }
      cout << endl;
      cout << "Total: $" << cost << endl;
   }
   if(option == 'i'){
      cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
      cout << SC.GetCustomerName() << "'s Shopping Cart - " << SC.GetDate() << endl;
      cout << endl;
      cout << "Item Descriptions" << endl;
      for(int i=0; i<SC.GetNumItemsInCart(); i++){
         cartItems[i].PrintItemDescription();
         cout << endl;
      }
   }
   if(option == 'a'){
      ItemToPurchase item;
      string name;
      string description;
      int price;
      int quantity;
      cout << "ADD ITEM TO CART" << endl;
      cout << "Enter the item name:" << endl;
      cin >> name;
      item.SetName(name);
      cout << "Enter the item description:" << endl;
      cin >> description;
      item.SetDescription(description);
      cout << "Enter the item price:" << endl;
      cin >> price;
      item.SetPrice(price);
      cout << "Enter the item quantity:" << endl;
      cin >> quantity;
      item.SetQuantity(quantity);
   }
   if(option == 'd'){
      ItemToPurchase item;
      string name;
      cout << "REMOVE ITEM FROM CART" << endl;
      cout << "Enter name of item to remove:" << endl;
      cin >> name;
      SC.RemoveItem(item);
   }
   if(option == 'c'){
      ItemToPurchase item;
      string name;
      int quantity;
      cout << "CHANGE ITEM QUANTITY" << endl;
      cout << "Enter the item name:" << endl;
      cin >> name;
      cout << "Enter the new quantity:" << endl;
      cin >> quantity;
      SC.ModifyItem(item);
   }
}


int main(){
   string name;
   string date;
   char option;
   cout << "Enter customer's name:" << endl;
   cin >> name;
   cout << "Enter today's date:" << endl;
   cin >> date;
   ShoppingCart SC = ShoppingCart(name, date);
   cout << "Customer name: " << SC.GetCustomerName() << endl;
   cout << "Today's date: " << SC.GetDate() << endl;
   PrintMenu();
   cout << "Choose an option:" << endl;
   cin >> option;
   if(option != 'a' || option != 'd' || option != 'c' || option != 'c' || option != 'i' || option != 'o' || option != 'q'){
      cout << "Choose an option:" << endl;
      cin >> option;
   }
   else{
      if(option != 'q'){
         ExecuteMenu(option, SC);
         PrintMenu();
         cout << "Choose an option:" << endl;
         cin >> option;
         while(option != 'q'){
         ExecuteMenu(option, SC);
         PrintMenu();
         cout << "Choose an option:" << endl;
         cin >> option;
         }
      }
   }
   return 0;
}
