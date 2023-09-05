#include <iostream>
#include <unordered_map>
#include <stdio.h>
using namespace std;

struct Node {
  int val;
  Node *next;
  Node *prev;
  Node(int x) : val(x), next(nullptr), prev(nullptr) {}
};

class LRUCache {
public:
  int capacity;
  Node *head;
  Node *tail;
  std::unordered_map<int, Node *> cache;
  LRUCache(int c) : head(new Node(-1)), tail(new Node(-1)), capacity(c) {
    head->next = tail;
    tail->prev = head;
  };
  int get(int key);
  void put(int key, int val);
  void display();
  void remove(Node* node);
  void insert(Node* node);
};

int LRUCache::get(int key) {
  if(cache.find(key) != cache.end()) {
    Node* node = cache[key];
    remove(node);
    insert(node);
    return node->val;
  }
  cout << "Could not finde key = " << key << endl;
  return -1;
}

void LRUCache::remove(Node* node) {
  Node* prev = node->prev;
  Node* next = node->next;

  prev->next = next;
  next->prev = prev;
}

void LRUCache::insert(Node* node) {
  Node* next = head->next;
  head->next = node;

  node->next = next;
  node->prev = head;
  next->prev = node;
}

void LRUCache::put(int key, int val) {
  cout << "Put = " << key << endl;
  // can find in cache
  if(cache.find(key) != cache.end()) {
    Node* remove = cache[key];
    LRUCache::remove(remove);
    delete remove;
  }
  // cannot find in cache
  Node* node = new Node(key);
  cache[key] = node;
  insert(node);
  if(cache.size() > capacity) {
    Node* remove = tail->prev;
    LRUCache::remove(remove);
    cache.erase(remove->val);
    delete remove;
  }
}

void LRUCache::display() {
  if(!head->next) {
    cout << "Cache is empty" << endl;
    return;
  }
  Node* node = head->next;
  cout << "LRU Cache = ";
  while(node && node != tail) {
    cout << node->val << " ";
    node = node->next;
  }
  cout << endl;
}

