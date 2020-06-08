//
// Created by rozi on 6/8/20.
//

#include "OrderManager.h"

OrderManager::OrderManager() = default;

void OrderManager::listOrders() {
    for(auto* order: orders){
        std::cout<<"Order #"<<order->getID()<<" - ";
        order->getOrderDetails()->print();
        std::cout<<"\n";
    }
}

void OrderManager::honorOrder(int orderID) {
    for(auto order: this->orders){
        if(order->getID() == orderID){
            order->getTable()->addFood(order->getOrderDetails());
            this->orders.remove(order);
            break;
        }
    }

}

void OrderManager::createOrder(HashTable<int>* orderTable, Table* table){
    auto* order = new Order(orderTable, table);
    this->orders.push_back(order);

}