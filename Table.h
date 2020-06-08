//
// Created by rozi on 6/8/20.
//

#ifndef HW5_TABLE_H
#define HW5_TABLE_H

#include <iostream>
#include "HashTable.h"
#include "Order.h"

class Table {
private:
    int id;
    static int nextID;
    HashTable<int>* food;
public:
    Table();
    int getID() const;
    void printFood();
    bool isEmpty();
    void addFood(HashTable<int>*);
};

std::ostream& operator<<(std::ostream& os, const Table& table);


#endif //HW5_TABLE_H
