//
// Created by rozi on 6/8/20.
//

#ifndef HW5_ORDERMANAGER_H
#define HW5_ORDERMANAGER_H
#include <list>
#include "Order.h"
#include "Table.h"

class OrderManager {
private:
    std::list<Order*> orders;
public:
    OrderManager();
    void listOrders();
    void honorOrder(int);
    void createOrder(HashTable<int>*, Table*);

};


#endif //HW5_ORDERMANAGER_H
