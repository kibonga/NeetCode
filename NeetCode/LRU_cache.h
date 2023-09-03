#include <iostream>
#include <map>
#include <stdio.h>
using namespace std;

struct Node {
  int val;
  Node *next;
  Node *prev;
  Node(int x) : val(x) {}
};

class LRUCache {
public:
  int capacity;
  int size;
  Node *head;
  Node *tail;
  std::map<int, Node *> map;
  LRUCache(int c) : head(nullptr), tail(nullptr), capacity(c), size(0){};
  int get(int key);
  void put(int key, int val);
  void display();
};

int LRUCache::get(int key) {
  if (!head) {
    cout << "LRU cache is empty" << endl;
    return -1;
  }
  Node *node = map[key];
  cout << "Iterate over map" << endl;
  for (auto m : map) {
    cout << "Key = " << m.first << " and Val = " << m.second << endl;
  }
  cout << endl;
  // Node *node = map[key];
  if (!node) {
    cout << "There is no node with key = " << key << endl;
    return -1;
  }

  if (head == tail) {
    cout << "There is only one element (HEAD and TAIL are the same)" << endl;
    return node->val;
  }

  if (node == head) {
    cout << "There are multiple elements, but we are fetching HEAD" << endl;
    return node->val;
  }

  if (node == tail) {
    node->next = head;
    head = node;
    node->prev->next = nullptr;
    tail = node->prev;
    return node->val;
  }

  node->prev->next = node->next;
  node->next = head;
  head = node;

  return node->val;
}

void LRUCache::put(int key, int val) {
  Node *node = map[key];
  if (node) {
    node->val = val;
    return;
  }

  Node *prev = nullptr;
  Node *next = head;
  Node *new_node = new Node(val);

  if (!head && !tail) {
    // cout << "This is INIT val = " << val << endl;
    map[key] = new_node;
    head = new_node;
    tail = new_node;
    size++;
    return;
  }

  if (size < capacity) {
    map[key] = new_node;
    new_node->next = next;
    next->prev = new_node;
    head = new_node;
    if (!tail) {
      tail = head;
      tail->next = nullptr;
    }
    size++;
    return;
  } else {
    map.erase(tail->val);
    node = tail;
    tail = tail->prev;
    delete node;
    map[key] = new_node;
    new_node->next = next;
    next->prev = new_node;
    head = new_node;
  }
}

void LRUCache::display() {
  Node *curr = head;
  if (!head) {
    cout << "Head is not defined" << endl;
    return;
  }
  cout << "Priority (high-low) = ";
  while (curr) {
    cout << curr->val << " ";
    curr = curr->next;
  }
  cout << endl;

  cout << "Map = ";
  for (auto &m : map) {
    cout << m.first << " ";
  }
  cout << endl;
}
