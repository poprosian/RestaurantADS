//
// Created by rozi on 6/8/20.
//

#ifndef HW5_ORDER_H
#define HW5_ORDER_H
#include "HashTable.h"
#include "Table.h"

class Table;

class Order {
private:
    int id;
    static int nextID;
    Table* table;
    HashTable<int>* orderDetails;
public:
    Order(HashTable<int>*, Table*);
    int getID() const;
    HashTable<int>* getOrderDetails() const;
    Table* getTable() const;

};


#endif //HW5_ORDER_H
