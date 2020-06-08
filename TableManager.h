//
// Created by rozi on 6/8/20.
//

#ifndef HW5_TABLEMANAGER_H
#define HW5_TABLEMANAGER_H
#include <list>
#include "Table.h"
#include "Order.h"

class TableManager {
private:
    std::list<Table*> tables;
public:
    TableManager();
    void listTables() const;
    Table* selectTable(int);
    void addTable();
    void removeTable(int);
};


#endif //HW5_TABLEMANAGER_H
