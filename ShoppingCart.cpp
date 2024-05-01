#include "ShopingCart.h"
#include <iostream>
#include <algorithm>

ShoppingCart::ShoppingCart(std::string customerName, std::string customerDate)
    : customerName(customerName), currentDate(customerDate) {}

std::string ShoppingCart::GetCustomerName() {
    return customerName;
}

std::string ShoppingCart::GetDate() {
    return currentDate;
}

void ShoppingCart::AddItem(ItemToPurchase item) {
    cartItems.push_back(item);
}

void ShoppingCart::RemoveItem(std::string itemName) {
    auto iter = std::remove_if(cartItems.begin(), cartItems.end(),
                               [&itemName](const ItemToPurchase& item) { return item.GetName() == itemName; });
    if (iter != cartItems.end()) {
        cartItems.erase(iter, cartItems.end());
        std::cout << "Item" << itemName << " removed from cart." << std::endl;
    } else {
        std::cout << "Item" << " not found in cart. Nothing removed." << std::endl;
        cout << endl;
    }
}

void ShoppingCart::ModifyItem(std::string itemName, int newQuantity) {
    auto iter = std::find_if(cartItems.begin(), cartItems.end(),
                             [&itemName](const ItemToPurchase& item) { return item.GetName() == itemName; });
    if (iter != cartItems.end()) {
        iter->SetQuantity(newQuantity);
        std::cout << "Item \"" << itemName << "\" quantity modified to " << newQuantity << "." << std::endl;
    } else {
        std::cout << "Item" << " not found in cart. Nothing modified." << std::endl;
    }
}

int ShoppingCart::GetNumItemsInCart() {
    return cartItems.size();
}

int ShoppingCart::GetCostOfCart() {
    int totalCost = 0;
    for (ItemToPurchase item : cartItems) {
        totalCost += item.GetPrice() * item.GetQuantity();
    }
    return totalCost;
}

void ShoppingCart::PrintTotal() {
    for (auto& entry : cartItems) {
        entry.PrintItemCost();
    }
    std::cout << "Total: $" << GetCostOfCart() << std::endl;
}

void ShoppingCart::PrintDescriptions() {
    for (auto& entry : cartItems) {
        entry.PrintItemDescription();
    }
}
