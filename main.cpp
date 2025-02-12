/**
* ---------------------------------------------------------------------
* @copyright
* Copyright 2024 Michelle Talley University of Central Arkansas
*
* @author: <Alex Belote>
* @course: Data Structures (CSCI 2320)
*
* @file main.cpp
* @brief Driver program for Linked List Lab
-----------------------------------------------------------------------
*/ 
#include <iostream>
#include "LinkedList.h"
#include "MessageBox.h"
#include <string>

int main() {
    std::cout << "Welcome to the LinkedList test program." << std::endl;
    std::cout << "\nTest some integer lists..." << std::endl;

    LinkedList<int> myIntList1;
    myIntList1.push_back(10);
    myIntList1.push_back(20);
    myIntList1.push_back(30);
    myIntList1.push_front(5);

    std::cout << " Integer list 1: ";
    myIntList1.print();

    std::cout << " Front element: " << myIntList1.front() << std::endl;
    std::cout << " Back element: " << myIntList1.back() << std::endl;

    std::cout << " Pop front: " << myIntList1.front() << std::endl;
    myIntList1.pop_front();
    std::cout << " Integer list 1: ";
    myIntList1.print();

    std::cout << " Pop front: " << myIntList1.front() << std::endl;
    myIntList1.pop_front();
    std::cout << " Integer list 1: ";
    myIntList1.print();

    std::cout << " Length of list 1 is " << myIntList1.size() << std::endl;
    std::cout << " List 1 is " << (myIntList1.empty() ? "empty" : "not empty") << std::endl;

    std::cout << " Pop back: " << myIntList1.back() << std::endl;
    myIntList1.pop_back();
    std::cout << " Pop back: " << myIntList1.back() << std::endl;
    myIntList1.pop_back();
    std::cout << " Integer list 1:";
    myIntList1.print();

    std::cout << " List 1 is " << (myIntList1.empty() ? "empty" : "not empty") << std::endl;

    myIntList1.push_back(10);
    myIntList1.push_back(20);
    myIntList1.push_back(30);
    std::cout << " Integer list 1: ";
    myIntList1.print();

    std::cout << " Copy integer list 1 to integer list 2." << std::endl;
    LinkedList<int> myIntList2 = myIntList1;

    std::cout << " Integer list 2: ";
    myIntList2.print();

    std::cout << " Pop 2 elements of the front of integer list 2." << std::endl;
    myIntList1.pop_front();
    myIntList1.print();
    myIntList2.print();

    std::cout << " Integer list 2 via std cout: " << myIntList2 << std::endl;

    std::cout << "\nTest some exceptions..." << std::endl;
    std::cout << " List 1 is " << (myIntList1.empty() ? "empty" : "not empty") << std::endl;

    try {
        std::cout << " Front element: " << myIntList1.front() << std::endl;
    } catch (const std::out_of_range &e) {
        std::cout << " Exception: " << e.what() << std::endl;
    }

    try {
        std::cout << " Back element: " << myIntList1.back() << std::endl;
    } catch (const std::out_of_range &e) {
        std::cout << " Exception: " << e.what() << std::endl;
    }

    std::cout << "\nTest some string lists..." << std::endl;

    LinkedList<std::string> myStringList1;
    myStringList1.push_front("spam?");
    myStringList1.push_front("some");
    myStringList1.push_front("have");
    myStringList1.push_front("Please, may I");

    std::cout << " String list 1: " << myStringList1 << std::endl;

    std::cout << "\nTry inserting an element at position 3" << std::endl;
    try {
        myStringList1.insert(3, "more");
        std::cout << " String list 1 has length " << myStringList1.size() << std::endl;  
    } 
    catch (std::out_of_range &e) {
        std::cout << " Exception: " << e.what() << std::endl;
    }
    std::cout << " String list 1: " << myStringList1 << std::endl;

    std::cout << "\nTry inserting an element at the beginning" << std::endl;
    try
        {
    myStringList1.insert(0, "Sir!  Sir!");  
    std::cout << " String list 1 has length " << myStringList1.size() << std::endl;
        }
        catch (std::out_of_range &e)
        {
            std::cout << "Exception: " << e.what() << std::endl;
        }
    std::cout << "String list 1: " << myStringList1 << std::endl;

    try
        {
            myStringList1.insert(myStringList1.size(), "I love spam!");
            std::cout << "String list 1 has length " << myStringList1.size() << std::endl;
        }
        catch(std::out_of_range &e)
        {
            std::cout << "Exception: " << e.what() << std::endl;
        }
    
    std::cout << "\nTry inserting an element at the end" << std::endl;
    myStringList1.insert(myStringList1.size(), "I love spam!");
    std::cout << " String list 1: " << myStringList1 << std::endl;

    std::cout << "\nTry inserting an element out of range" << std::endl;
    try {
        myStringList1.insert(7, "error");
        std::cout << " String list 1 has length " << myStringList1.size() << std::endl;
    } catch (std::out_of_range &e) {
        std::cout << " Exception: " << e.what() << std::endl;
    }
    std::cout << " Expected failure trying to insert out of range" << std::endl;

    std::cout << "\nRemove the first and last element and print result" << std::endl;
    myStringList1.pop_front();
    myStringList1.pop_back();
    std::cout << " String list 1: " << myStringList1 << std::endl;

    std::cout << "Goodbye!" << std::endl;
    return 0;
}
