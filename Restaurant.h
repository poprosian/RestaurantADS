//
// Created by rozi on 6/8/20.
//

#ifndef HW5_RESTAURANT_H
#define HW5_RESTAURANT_H
#include "TableManager.h"
#include "OrderManager.h"

class Restaurant {
private:
    TableManager* tableManager;
    OrderManager* orderManager;
public:
    Restaurant();
    void tableManagerMode();
    void orderManagerMode();
};


#endif //HW5_RESTAURANT_H
