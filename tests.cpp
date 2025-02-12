/**
* ---------------------------------------------------------------------
* @copyright
* Copyright 2024 Michelle Talley University of Central Arkansas
*
* @author: <Alex Belote>
* @course: Data Structures (CSCI 2320)
*
* @file tests.cpp
* @brief Student testing code outside of the required main.cpp.
-----------------------------------------------------------------------
*/

#include <iostream>
#include "LinkedList.h"

void testPushBack() {
    LinkedList<int> list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    std::cout << "Expected: 10 20 30, Got: " << list.toString() << std::endl;
}

void testInsert() {
    LinkedList<int> list;
    list.push_back(10);
    list.insert(0, 5);
    list.insert(2, 15);
    std::cout << "Expected: 5 10 15, Got: " << list.toString() << std::endl;
}

void testPopFront() {
    LinkedList<int> list;
    list.push_back(10);
    list.push_back(20);
    list.pop_front();
    std::cout << "Expected: 20, Got: " << list.toString() << std::endl;
}

void testPopBack() {
    LinkedList<int> list;
    list.push_back(10);
    list.push_back(20);
    list.pop_back();
    std::cout << "Expected: 10, Got: " << list.toString() << std::endl;
}

int main() {
    testPushBack();
    testInsert();
    testPopFront();
    testPopBack();
    return 0;
}

