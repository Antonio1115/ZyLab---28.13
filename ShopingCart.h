#ifndef SHOPPING_CART_H
#define SHOPPING_CART_H

#include <string>
#include <vector>
#include "ItemToPurchase.h"

class ShoppingCart {
public:
    ShoppingCart(std::string customerName = "none", std::string customerDate = "January 1, 2016");

    std::string GetCustomerName();
    std::string GetDate();

    void AddItem(ItemToPurchase item);
    void RemoveItem(std::string itemName);
    void ModifyItem(std::string itemName, int newQuantity);

    int GetNumItemsInCart();
    int GetCostOfCart();
    void PrintTotal();
    void PrintDescriptions();

    std::vector<ItemToPurchase> GetCartItems() { return cartItems; }

private:
    std::string customerName;
    std::string currentDate;
    std::vector<ItemToPurchase> cartItems;
};

#endif
