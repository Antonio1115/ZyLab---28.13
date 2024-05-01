#include <iostream>
#include <vector>
#include <algorithm>
#include "ShopingCart.h"

using namespace std;

void PrintMenu() {
    cout << "MENU" << endl;
    cout << "a - Add item to cart" << endl;
    cout << "d - Remove item from cart" << endl;
    cout << "c - Change item quantity" << endl;
    cout << "i - Output items' descriptions" << endl;
    cout << "o - Output shopping cart" << endl;
    cout << "q - Quit" << endl;
    cout << endl;
}

void ExecuteMenu(char option, ShoppingCart& SC) {
    if (option == 'o') {
        cout << "OUTPUT SHOPPING CART" << endl;
        cout << SC.GetCustomerName() << "'s Shopping Cart - " << SC.GetDate() << endl;
        cout << "Number of Items: " << SC.GetNumItemsInCart() << endl;
        if(SC.GetNumItemsInCart() == 0){
           cout << endl;
           cout << "SHOPPING CART IS EMPTY" << endl;
           cout << endl;
        }
        SC.PrintTotal();
        cout << endl;
    }
    else if (option == 'i') {
        cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
        cout << SC.GetCustomerName() << "'s Shopping Cart - " << SC.GetDate() << endl;
        cout << "Item Descriptions" << endl;
        SC.PrintDescriptions();
    }
    else if (option == 'a') {
        ItemToPurchase item;
        string name, description;
        int price, quantity;
        cout << "ADD ITEM TO CART" << endl;
        cout << "Enter the item name:" << endl;
        cin.ignore(); // Clear the newline character from the buffer
        getline(cin, name);
        item.SetName(name);
        cout << "Enter the item description:" << endl;
        getline(cin, description);
        item.SetDescription(description);
        cout << "Enter the item price:" << endl;
        cin >> price;
        item.SetPrice(price);
        cout << "Enter the item quantity:" << endl;
        cin >> quantity;
        item.SetQuantity(quantity);
        SC.AddItem(item);
    }
    else if (option == 'd') {
        string name;
        cout << "REMOVE ITEM FROM CART" << endl;
        cout << "Enter name of item to remove:" << endl;
        cin.ignore(); // Clear the newline character from the buffer
        getline(cin, name);
        SC.RemoveItem(name);
    }
    else if (option == 'c') {
        string name;
        int quantity;
        cout << "CHANGE ITEM QUANTITY" << endl;
        cout << "Enter the item name:" << endl;
        cin.ignore(); // Clear the newline character from the buffer
        getline(cin,name);
        cout << "Enter the new quantity:" << endl;
        cin >> quantity;
        SC.ModifyItem(name, quantity);
    }
}

int main() {
    string name, date;
    char option;
    cout << "Enter customer's name:" << endl;
    getline(cin,name);
    cout << "Enter today's date:" << endl;
    cout << endl;
    getline(cin, date);
    ShoppingCart SC(name, date);
    cout << "Customer name: " << SC.GetCustomerName() << endl;
    cout << "Today's date: " << SC.GetDate() << endl;
    cout << endl;
    PrintMenu();
    cout << "Choose an option:" << endl;
    cin >> option;
    cin.ignore(); // Clear the newline character from the buffer
    while(option != 'a' && option != 'd' && option != 'c' && option != 'i' && option != 'o' && option != 'q'){
      cout << "Choose an option:" << endl;
      cin >> option;
      cin.ignore(); 
    }  
    while (option != 'q') {
      ExecuteMenu(option, SC);
      PrintMenu();
      cout << "Choose an option:" << endl;
      cin >> option;
      cin.ignore(); 
    }
    return 0;
}
