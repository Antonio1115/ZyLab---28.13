#include <iostream>
using namespace std;

#include "ItemToPurchase.h"

    ItemToPurchase::ItemToPurchase(string userName, string userDescription, int userPrice, int userQuantity){
    this->name = userName;
    this->description = userDescription;
    this->price = userPrice;
    this->quantity = userQuantity;
    }

    ItemToPurchase::ItemToPurchase(string userName, int userPrice, int userQuantity){
   
   this->name = userName;
   this->price = userPrice;
   this->quantity = userQuantity;
   
    }    
   
    void ItemToPurchase::SetPrice(int userPrice){
    this->price = userPrice;  
    }
    void ItemToPurchase::SetName(string userName){
      this->name = userName;
    }
    void ItemToPurchase::SetQuantity(int userQuantity){
      this->quantity = userQuantity;
    }
    void ItemToPurchase::SetCost(int userPrice, int userQuantity){
      cost = userPrice * userQuantity;
    }
    void ItemToPurchase::SetDescription(string userDescription){
    this->description = userDescription;
    }
    int ItemToPurchase::GetPrice(){
      return price;
    }
    string ItemToPurchase::GetName() const{
      return name;
    }
    int ItemToPurchase::GetQuantity(){
      return quantity;
    }    
    int ItemToPurchase::GetCost(){
      return cost;
    }  
    string ItemToPurchase::GetDescription() const{
        return description;
    }
    void ItemToPurchase::PrintItemCost() {
    std::cout << name << ": $" << price << std::endl;
   }

   void ItemToPurchase::PrintItemDescription() {
    std::cout << name << ": " << description << std::endl;
   }
