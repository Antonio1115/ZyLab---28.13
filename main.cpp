#include <iostream>
using namespace std;
#include "ShoppingCart.h"


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
    int i=0;
    if(option == 'o'){
        cout << "OUTPUT SHOPPING CART" << endl;
        cout << SC.GetCustomerName() << "'s Shopping Cart - " << SC.GetDate() << endl;
        cout << "Number of Items: " << SC.GetNumItemsInCart() << endl;
        for(int i=0; i<SC.GetNumItemsInCart(); i++){
            
        }

    Nike Romaleos 2 @ $189 = $378
    Chocolate Chips 5 @ $3 = $15
    Powerbeats 2 Headphones 1 @ $128 = $128

    Total: $521
   
   
}

int main(){
    string name;
    string date;
    char option;
    cout << "Enter customer's name:" << endl;
    cin >> name;
    cout << "Enter today's date:" << endl;
    cin >> date;
    ShoppingCart SC = new ShoppingCart(name, date);
    cout << "Customer name: " <<  SC.GetCustomerName() << endl;
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

    return 0;
}
