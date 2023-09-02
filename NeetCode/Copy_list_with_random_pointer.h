#include <iostream>
#include <map>
#include <stdio.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode *random;
  ListNode(int x) : val(x), next(nullptr), random(nullptr) {}
};

ListNode *deep_copy(ListNode *head) {
  ListNode *new_node = nullptr;
  ListNode *curr = head;
  ListNode *prev = nullptr;
  map<ListNode *, ListNode *> map;

  while (curr) {
    new_node = new ListNode(curr->val);
    if (prev) {
      prev->next = new_node;
    }
    prev = new_node;
    map[curr] = new_node;
    curr = curr->next;
  }

  curr = head;
  new_node = nullptr;

  while (curr) {
    new_node = map[curr];
    new_node->random = map[curr->random];
    curr = curr->next;
  }

  new_node = map[head];
  return new_node;
}

void display(ListNode *head) {
  ListNode *curr = head;
  while (curr) {
    ListNode *next = curr->next;
    ListNode *random = curr->random;
    cout << "Node = " << curr->val << endl;
    if (next) {
      cout << "Next = " << next->val << endl;
    } else {
      cout << "Next = NULL" << endl;
    }
    if (random) {
      cout << "Random = " << random->val << endl;
    } else {
      cout << "Random = NULL" << endl;
    }
    curr = curr->next;
    cout << endl << "-------" << endl;
  }
}
