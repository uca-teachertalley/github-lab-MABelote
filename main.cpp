#include <iostream>
#include "LinkedList.h"
#include <string>

int main() {
    std::cout << "Welcome to the LinkedList test program." << std::endl;

    std::cout << "\nTest some integer lists..." << std::endl;  // <== Added newline

    LinkedList<int> myIntList1;
    myIntList1.push_back(10);
    myIntList1.push_back(20);
    myIntList1.push_back(30);
    myIntList1.push_front(5);

    std::cout << "Integer list 1: ";
    myIntList1.print();
    std::cout << std::endl;  // <== Ensure blank line

    std::cout << "Front element: " << myIntList1.front() << std::endl;
    std::cout << "Back element: " << myIntList1.back() << std::endl;
    std::cout << std::endl;  // <== Extra newline

    std::cout << "Pop front: " << myIntList1.front() << std::endl;
    myIntList1.pop_front();
    std::cout << "Integer list 1: ";
    myIntList1.print();
    std::cout << std::endl;  // <== Ensure spacing

    std::cout << "\nTest some string lists..." << std::endl;  // <== Ensure section header spacing

    LinkedList<std::string> myStringList1;
    myStringList1.push_front("spam?");
    myStringList1.push_front("some");
    myStringList1.push_front("have");
    myStringList1.push_front("Please, may I");

    std::cout << "String list 1: " << myStringList1 << std::endl;
    std::cout << std::endl;  // <== Extra space to match expected output

    std::cout << "Try inserting an element at position 3" << std::endl;
    try {
        myStringList1.insert(3, "more");
        std::cout << "String list 1 has length " << myStringList1.size() << std::endl;  
    } 
    catch (std::out_of_range &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << "String list 1: " << myStringList1 << std::endl;
    std::cout << std::endl;  // <== Ensure blank line

    std::cout << "Try inserting an element at the beginning" << std::endl;
    try {
        myStringList1.insert(0, "Sir! Sir!");
    } 
    catch (std::out_of_range &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << "String list 1: " << myStringList1 << std::endl;
    std::cout << std::endl;  // <== Ensure blank line

    std::cout << "Try inserting an element at the end" << std::endl;
    try {
        myStringList1.insert(myStringList1.size(), "I love spam!");
        std::cout << "String list 1 has length " << myStringList1.size() << std::endl;  
    } 
    catch (std::out_of_range &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << "String list 1: " << myStringList1 << std::endl;
    std::cout << std::endl;  // <== Ensure blank line

    std::cout << "Try inserting an element out of range" << std::endl;
    std::cout << "String list 1 has length " << myStringList1.size() << std::endl;
    try {
        myStringList1.insert(100, "This should fail");
    } 
    catch (std::out_of_range &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << "Expected failure trying to insert out of range" << std::endl;
    std::cout << std::endl;  // <== Ensure blank line

    std::cout << "Remove the first and last element and print result" << std::endl;
    myStringList1.pop_front();
    myStringList1.pop_back();
    std::cout << "String list 1: " << myStringList1 << std::endl;
    std::cout << std::endl;  // <== Ensure blank line

    std::cout << "Goodbye!" << std::endl;
    return 0;
}
