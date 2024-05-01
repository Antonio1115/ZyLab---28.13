#ifndef ITEM_TO_PURCHASE_H
#define ITEM_TO_PURCHASE_H

#include <string>
using namespace std;
 
 class ItemToPurchase {

public:

    ItemToPurchase(string userName, string userDescription = "none", int userPrice = 0, int userQuantity = 0);
    ItemToPurchase(string userName = "none", int userPrice = 0, int userQuantity = 0);
   
   void SetPrice(int userPrice);
   void SetName(string userName);
   void SetQuantity(int userQuantity); 
   void SetCost(int userPrice, int userQuantity);
   void SetDescription(string userDescription);
   
    int GetPrice();
    string GetName() const;
    int GetQuantity();
    int GetCost();
    string GetDescription() const;

    void PrintItemCost();
    void PrintItemDescription();


    
private:

    string name;
    int price;
    int quantity;
    int cost;
    string description;

 };

#endif