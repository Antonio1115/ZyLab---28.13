#include <iostream>
#include <iomanip>
using namespace std;

#include "ShopingCart.h"

void PrintMenu() {
   cout << "a - Add item to cart" << endl;
   cout << "d - Remove item from cart" << endl;
   cout << "c - Change item quantity" << endl;
   cout << "i - Output items' descriptions" << endl;
   cout << "o - Output shopping cart" << endl;
   cout << "q - Quit" << endl;
   
}

void ExecuteMenu(char option, ShoppingCart& theCart) {
   /* Type your code here */
   
}

int main() {
   /* Type your code here */
   char choice;
   ShoppingCart cart;
   
   do{
      PrintMenu();
      
      cout << "Choose an option" << endl;
      cin >> choice;
      
      ExecuteMenu(choice,cart);
   }
   while(choice != 'q');
      
   
   return 0;
}