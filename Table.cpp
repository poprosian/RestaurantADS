//
// Created by rozi on 6/8/20.
//

#include "Table.h"

int Table::nextID = 1;

Table::Table()
    :id(nextID++), food(nullptr){
}
int Table::getID() const {
    return this->id;
}

void Table::printFood() {
    this->food->print();
}

bool Table::isEmpty() {
    return this->food == nullptr;
}

void Table::addFood(HashTable<int>* foodOrder) {
    this->food = foodOrder;
}


std::ostream &operator<<(std::ostream &os, const Table &table) {
    os << "Table #"<<table.getID()<<" ";
    return os;
}
