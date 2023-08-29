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
  if (head == nullptr && merge_head == nullptr) {
    cout << "Both lists are empty" << endl;
    return;
  }

  Node *node1 = head;
  Node *node2 = merge_head;
  Node *next1 = nullptr;
  Node *next2 = nullptr;

  while ((node1->next != nullptr) && (node2->next != nullptr)) {
    if (node2->value < node1->next->value) {
      next1 = node1->next;
      node1->next = node2;
      while (node2->next != nullptr && node2->next->value < next1->value) {
        node2 = node2->next;
      }
      next2 = node2->next;
      node2->next = next1;
      node2 = next2;
      node1 = next1;
    }

    if (node1->value < node2->next->value) {
      next2 = node2->next;
      node2->next = node1;
      while (node1->next != nullptr && node1->next->value < next2->value) {
        node1 = node1->next;
      }
      next1 = node1->next;
      node1->next = next2;
      node1 = next1;
      node2 = next2;
    }
  }

  if (node1->next == nullptr) {
    node1->next = node2;
    return;
  }

  if (node2->next == nullptr) {
    node2->next = node1;
    return;
  }
}
