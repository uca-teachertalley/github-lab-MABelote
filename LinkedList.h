#ifndef LINKEDLIST_H
#define LINKEDLIST_H

/**
* ---------------------------------------------------------------------
* @copyright
* Copyright 2024 Michelle Talley University of Central Arkansas
*
* @author: <Alex Belote>
* @course: Data Structures (CSCI 2320)
*
* @file LinkedList.h
* @brief Declaration of the LinkedList class and its methods.
-----------------------------------------------------------------------
*/

#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>

template <typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int count;

public:
    LinkedList() : head(nullptr), tail(nullptr), count(0) {}

    LinkedList(const LinkedList& other) : head(nullptr), tail(nullptr), count(0) {
        Node* current = other.head;
        while (current != nullptr) {
            push_back(current->data);
            current = current->next;
        }
    }

    ~LinkedList() { clear(); }

    void clear() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        count = 0;
    }

    bool empty() const { return count == 0; }

    int size() const { return count; }

    void push_back(const T& value) {
        Node* newNode = new Node(value);
        if (empty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        count++;
    }

    void push_front(const T& value) {
        Node* newNode = new Node(value);
        if (empty()) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
        count++;
    }

    void insert(int index, const T& value) {
        if (index < 0 || index > count) {
            throw std::out_of_range("Index out of bounds");
        }
        if (index == 0) {
            push_front(value);
        } else if (index == count) {
            push_back(value);
        } else {
            Node* newNode = new Node(value);
            Node* temp = head;
            for (int i = 0; i < index - 1; i++) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
            count++;
        }
    }

    void pop_back() {
        if (empty()) throw std::out_of_range("Index out of bounds");
        if (head == tail) {
            delete head;
            head = tail = nullptr;
        } else {
            Node* temp = head;
            while (temp->next != tail) {
                temp = temp->next;
            }
            delete tail;
            tail = temp;
            tail->next = nullptr;
        }
        count--;
    }

  void erase(int index) {
        if (index < 0 || index >= count) {
            throw std::out_of_range("Index out of bounds");
        }
        if (index == 0) {
            pop_front();
        } else {
            Node* temp = head;
            for (int i = 0; i < index - 1; i++) {
                temp = temp->next;
            }
            Node* nodeToDelete = temp->next;
            temp->next = nodeToDelete->next;
            if (nodeToDelete == tail) {
                tail = temp; 
            }
            delete nodeToDelete;
            count--;
        }
    }

    void pop_front() {
        if (empty()) throw std::out_of_range("Index out of bounds");
        Node* temp = head;
        head = head->next;
        delete temp;
        if (!head) tail = nullptr;
        count--;
    }

    T front() const {
        if (empty()) throw std::out_of_range("Index out of bounds");
        return head->data;
    }

    T back() const {
        if (empty()) throw std::out_of_range("Index out of bounds");
        return tail->data;
    }

std::string toString() const {
    std::stringstream ss;
    Node* temp = head;
    while (temp) {
        ss << temp->data;
        if (temp->next) ss << " "; 
        temp = temp->next;
    }
    return ss.str();
}

    void print() const { std::cout << toString() << std::endl; }

 friend std::ostream& operator<<(std::ostream& os, const LinkedList<T>& list) {
        os << list.toString();
        return os;
    }

};

#endif // LINKEDLIST_H
