#include <iostream>
#include <stdio.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *remove_nth_from_end(ListNode *head, int n) {
  ListNode *curr = head;
  ListNode *trail = nullptr;

  if (!head) {
    cout << "List already empty" << endl;
    return head;
  }

  int i = 1;
  while (curr) {
    if ((i > n) && (i % n == 0)) {
      for (int k = 0; k < n; k++) {
        if (!trail) {
          trail = head;
        } else {
          trail = trail->next;
        }
      }
    }
    i++;
    curr = curr->next;
  }

  for (i = 0; i < n - 1; i++) {
    if (!trail) {
      trail = head;
      continue;
    }
    trail = trail->next;
  }

  if (!trail && (n == 1)) {
    cout << "There is only one element in list" << endl;
    head = nullptr;
    return head;
  }

  curr = trail->next;
  trail->next = curr->next;
  delete curr;

  return head;
}

void display(ListNode *head) {
  ListNode *node = head;
  cout << "List = ";
  while (node) {
    cout << node->val << " ";
    node = node->next;
  }
  cout << endl;
}
