//
// Created by rozi on 6/8/20.
//

#include "TableManager.h"

TableManager::TableManager()= default;

void TableManager::listTables() const {
    for(auto table: this->tables){
        std::cout<<"Table #"<<table->getID()<<'\n';
    }

}

Table* TableManager::selectTable(int tableID) {
    for(auto table: this->tables){
        if(table->getID() == tableID){
            return table;
        }
    }
    return nullptr;
}

void TableManager::addTable() {
    auto* newTable = new Table();
    this->tables.push_back(newTable);
}

void TableManager::removeTable(int removeID) {
    for(auto table: this->tables){
        if(table->getID() == removeID){
            tables.remove(table);
            delete table;
            break;
        }
    }
}

