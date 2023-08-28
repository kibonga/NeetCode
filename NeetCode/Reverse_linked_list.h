#pragma once
#include <iostream>
#include <stdio.h>
using namespace std;

class Node {
public:
    int value;
    Node* next;
    Node(int x) {
        value = x;
        next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;
    LinkedList() { head = nullptr; }
    void display();
    void reverse();
    void push(int x);
    ~LinkedList();
};

void LinkedList::push(int x) {
    Node* new_node = new Node(x);
    if (head == nullptr) {
        cout << "Head node inserted" << endl;
        head = new_node;
        return;
    }
   
    Node* node = head;
    while (node->next != nullptr) {
        node = node->next;
    }
    node->next = new_node;

    new_node = nullptr;
    delete new_node;
}

void LinkedList::display() {
    if (head == nullptr) {
        cout << "Linked list is empty" << endl;
        return;
    }
    
    Node* node = head;
    cout << "Linked List = ";
    while (node) {
        cout << node->value << " ";
        node = node->next;
    }
    node = nullptr;
    delete node;
}

void LinkedList::reverse() {
    if (head == nullptr) {
        cout << "Cannot reverse, Linked list is empty" << endl;
        return;
    }

    Node* node = head;
    Node* prev = nullptr;
    Node* next = nullptr;

    while (node != nullptr) {
        next = node->next;
        node->next = prev;
        prev = node;
        node = next;
    }
    head = prev;
    prev = nullptr;
}

LinkedList::~LinkedList() {
    Node* node = head;
    while (node != nullptr) {
        Node* temp = node;
        node = node->next;
        delete temp;
    }
}
