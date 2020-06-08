cmake_minimum_required(VERSION 3.16)
project(HW5)

set(CMAKE_CXX_STANDARD 14)

add_executable(HW5 main.cpp HashTable.h HashNode.h Table.cpp Table.h Order.cpp Order.h OrderManager.cpp OrderManager.h TableManager.cpp TableManager.h Restaurant.cpp Restaurant.h)