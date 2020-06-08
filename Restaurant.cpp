//
// Created by rozi on 6/8/20.
//

#include "Restaurant.h"
#include <iostream>

void Restaurant::orderManagerMode() {

    int response;
    while(true) {
        std::cout<<"\n\nOrder manager\n";
        std::cout << "(1) List orders - (2) Send order - (0) Exit order manager\n";
        std::cin >> response;
        if(response == 1){
            std::cout<<"========================================\n";
            this->orderManager->listOrders();
            std::cout<<"========================================\n";
        } else if(response == 2){
            int orderID;
            std::cout<<"Order ID: ";
            std::cin>>orderID;
            this->orderManager->honorOrder(orderID);
            std::cout<<"=====================\n";
            std::cout<<"Order sent to table!\n";
            std::cout<<"=====================\n";
        } else if(response == 0){
            break;
        }
    }

}

void Restaurant::tableManagerMode() {

    int response;
    while(true){
        std::cout<<"\n\nTable manager\n";
        std::cout<<"(1) Select table - (2) List tables - (3) Add table - (4) Remove table - (0) Exit table manager\n";
        std::cin>>response;
        if(response == 1){
            int tableID;
            std::cout<<"Table ID: ";
            std::cin>>tableID;
            int tableResponse;
            while(true){
                auto* selectedTable = this->tableManager->selectTable(tableID);
                std::cout<<"\n\nViewing table #"<<tableID<<"\n";
                std::cout<<"(1) Order food - (2) View food on table - (0) Back\n";
                std::cin>>tableResponse;
                if(tableResponse == 1){
                    std::cout<<"\n\nOrdering mode:\n";
                    int orderResponse;
                    auto* orderTable = new HashTable<int>;
                    while(true){
                        std::cout<<"(1) Add food item - (0) Send order\n";
                        std::cin>>orderResponse;
                        if(orderResponse == 1){
                            std::string foodName;
                            int quantity;
                            std::cout<<"Food name: ";
                            std::cin.ignore();
                            std::getline(std::cin, foodName);
                            std::cout<<"Quantity: ";
                            std::cin>>quantity;
                            orderTable->insert(foodName, quantity);
                        } else if(orderResponse == 0 and !orderTable->isEmpty()){
                            this->orderManager->createOrder(orderTable, selectedTable);
                            std::cout<<"===========\n";
                            std::cout<<"Order sent!\n";
                            std::cout<<"============\n";
                            break;
                        } else if(orderResponse == 0){
                            std::cout<<"=====================================\n";
                            std::cout<<"You haven't ordered anything yet!\n";
                            std::cout<<"======================================\n";
                        }
                    }

                } else if(tableResponse == 2){
                    if(!selectedTable->isEmpty()){
                        selectedTable->printFood();
                        std::cout<<std::endl;
                    } else {
                        std::cout<<"========================================\n";
                        std::cout<<"There is currently no food on the table!\n";
                        std::cout<<"=========================================";
                    }

                } else if(tableResponse == 0){
                    break;
                }
            }
        } else if(response == 2){
            this->tableManager->listTables();
        } else if(response == 3) {
            this->tableManager->addTable();
        } else if (response == 4){
            int tableID;
            std::cout<<"Table ID: ";
            std::cin>>tableID;
            this->tableManager->removeTable(tableID);
        } else if(response == 0){
            break;
        }
    }

}

Restaurant::Restaurant()
    :tableManager(nullptr), orderManager(new OrderManager()){
    std::cout<<"ADS Restaurant\n";
    int response;
    while(true){
        if(this->tableManager == nullptr){
            this->tableManager = new TableManager();
            int tableCount;
            std::cout<<"There are no tables initialized! Please enter the number of tables you wish to have (1,2,.. ): \n";
            std::cin>>tableCount;
            for(int i=0;i<tableCount;i++){
                this->tableManager->addTable();
            }
        }
        std::cout<<"(1) Table mode - (2) OrderManager mode - (3) Exit\n";
        std::cin>>response;
        if(response == 1){
            tableManagerMode();
        } else if(response == 2){
            orderManagerMode();
        } else if(response == 3){
            break;
        }
    }

}


