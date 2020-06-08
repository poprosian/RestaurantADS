//
// Created by rozi on 6/8/20.
//

#include "Order.h"

int Order::nextID = 1;

Order::Order(HashTable<int> *foodOrder, Table* table)
    :orderDetails(foodOrder), id(nextID++), table(table){
}

int Order::getID() const {
    return this->id;
}

HashTable<int> *Order::getOrderDetails() const{
    return this->orderDetails;
}

Table* Order::getTable() const {
    return this->table;
}
