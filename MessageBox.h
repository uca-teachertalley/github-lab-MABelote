#ifndef MESSAGEBOX_H_
#define MESSAGEBOX_H_

/**
* ---------------------------------------------------------------------
* @copyright
* Copyright 2024 Michelle Talley University of Central Arkansas
*
* @author: Alex Belote
* @course: Data Structures (CSCI 2320)
*
* @file MessageBox.h
* @brief Declaration of the MessageBox class and its methods.
-----------------------------------------------------------------------
*/

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

const int DEFAULT_SIZE = 10;

template<typename T>
class MessageBox 
{
 private:
    T* messages;
    int mySize;
    int count;
    bool *emptyBox;

 public:
    MessageBox(int numEntries = DEFAULT_SIZE) 
    {
        mySize = numEntries;
        count = 0;
        messages = new T[mySize];
        emptyBox = new bool[mySize];
        for (int i = 0; i < mySize; i++) {
            messages[i] = T();
            emptyBox[i] = true;
        }
    }

    ~MessageBox() 
    {
        delete[] messages;
        delete[] emptyBox;
    }

    void send(int index, const T& message) 
    {
        if (index < 0 || index >= mySize) 
        {
            throw std::out_of_range("Index out of bounds");
        }
        if (full(index)) 
        {
            throw std::runtime_error("Index out of bounds");
        }
        messages[index] = message;
        emptyBox[index] = false;
        count++;
    }

    T receive(int index) 
    {
        if (index < 0 || index >= mySize) 
        {
            throw std::out_of_range("Index out of bounds");
        }
        if (empty(index)) 
        {
            throw std::runtime_error("Index out of bounds");
        }
        T message = messages[index];
        messages[index] = T();
        emptyBox[index] = true;
        count--;
        return message;
    }

    bool empty() const { return count == 0; }

    bool empty(int index) const
    {
        if (index < 0 || index >= mySize)
        {
            throw std::out_of_range("Index out of bounds");
        }
        return emptyBox[index] == true;
    }

    bool full() const { return count == mySize; }

    bool full(int index) const { return !empty(index); }

    int getSize() const { return mySize; }

    int getCount() const { return count; }

    std::string toString() const 
    {
        std::stringstream ss;
        ss << std::fixed << std::setprecision(1);
        int printed_count = 0;
        for (int i = 0; i < mySize; i++) {
            if (!empty(i)) {
                ss << messages[i];
                printed_count++;
                if (printed_count < count) {
                    ss << " ";
                }
            }
        }
        return ss.str();
    }

    void print() const
    {
        std::cout << toString() << std::endl;
    }

void print_verbose() const
{
    for (int i = 0; i < mySize; i++)
    {
        if (empty(i))
        {
            std::cout << i << ":<empty>:" << std::endl;  
        }
        else
        {
            std::cout << i << ":" << messages[i] << ":" << std::endl;  
        }
     
    }
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const MessageBox<T>& messageBox) 
{
    os << messageBox.toString();
    return os;
}

#endif  // MESSAGEBOX_H_
