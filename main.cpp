/**
* ---------------------------------------------------------------------
* @copyright
* Copyright 2024 Michelle Talley University of Central Arkansas
*
* @author: <Alex Belote>
* @course: Data Structures (CSCI 2320)
*
* @file main.cpp
* @brief Driver program for MessageBox demonstration program.
-----------------------------------------------------------------------
*/

#include <iostream>
#include "LinkedList.h"

int main() {
    std::cout << "Welcome to the LinkedList test program." << std::endl;

    LinkedList<int> myIntList1;
    myIntList1.push_back(10);
    myIntList1.push_back(20);
    myIntList1.push_back(30);
    myIntList1.push_front(5);

    std::cout << "Integer list 1: ";
    myIntList1.print();

    std::cout << "Front element: " << myIntList1.front() << std::endl;
    std::cout << "Back element: " << myIntList1.back() << std::endl;

    std::cout << "Pop front: " << myIntList1.front() << std::endl;
    myIntList1.pop_front();
    myIntList1.print();

    LinkedList<std::string> myStringList1;
    myStringList1.push_front("spam?");
    myStringList1.push_front("some");
    myStringList1.push_front("have");
    myStringList1.push_front("Please, may I");

    std::cout << "String list 1: " << myStringList1 << std::endl;

    std::cout << "\nTry inserting an element at position 3" << std::endl;
    myStringList1.insert(3, "more");
    std::cout << "String list 1 has length " << myStringList1.size() << std::endl;
    std::cout << "String list 1: " << myStringList1 << std::endl;

    std::cout << "Goodbye!" << std::endl;
    return 0;
}
