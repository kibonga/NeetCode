#include <iostream>
#include <stdio.h>
using namespace std;

struct Node {
public:
  int value;
  Node *next;
  Node(int x) : value(x), next(nullptr) {}
};

class LinkedList {
public:
  Node *head;
  LinkedList() : head(nullptr) {}
  ~LinkedList();
  void add(int x);
  void display();
  void merge(Node *merge_head);
};

LinkedList::~LinkedList() {
  Node *node = head;
  Node *node_delete = nullptr;
  while (node != nullptr) {
    node_delete = node;
    node = node->next;
    delete node_delete;
  }
}

void LinkedList::add(int x) {
  Node *new_node = new Node(x);

  if (head == nullptr) {
    cout << "Head node created" << endl;
    head = new_node;
    return;
  }

  if (x < head->value) {
    new_node->next = head;
    head = new_node;
    return;
  }

  Node *node = head;
  while ((node->next != nullptr) && (x > node->next->value)) {
    node = node->next;
  }
  if (node->next != nullptr) {
    new_node->next = node->next;
  }
  node->next = new_node;

  return;
}

void LinkedList::display() {
  if (head == nullptr) {
    cout << "Linked list is empty" << endl;
    return;
  }

  Node *node = head;
  cout << "Linked list = ";
  while (node != nullptr) {
    cout << node->value << " ";
    node = node->next;
  }
  cout << endl;
}

void LinkedList::merge(Node *merge_head) {
    if (!head && !merge_head) {
        cout << "Both lists are empty" << endl;
        return;
    }
    if (!head) {
        cout << "List A is empty" << endl;
        head = merge_head;
        return;
    }
    if (!merge_head) {
        cout << "List B is empty" << endl;
        return;
    }
    if (merge_head == head) {
        cout << "Both heads point to the same list" << endl;
        return;
    }

    Node* a = head;
    Node* b = merge_head;
    Node* prev = nullptr;

    while (a && b) {
        if (a->value < b->value) {
            prev = a;
            a = a->next;
            continue;
        }
        if (!prev) {
            head = b;
        }
        else {
            prev->next = b;
        }
        prev = b;
        b = b->next;
        prev->next = a;
    }

    if (b && prev) {
        prev->next = b;
    }
}
