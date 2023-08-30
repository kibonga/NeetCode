#include <iostream>
#include <stdio.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

void display(ListNode *head) {
  ListNode *curr = head;
  cout << "List = ";
  while (curr) {
    cout << curr->val << " ";
    curr = curr->next;
  }
  cout << endl;
}

ListNode *remove(ListNode *head, int n) {
  ListNode *curr = head;
  ListNode *prev = head;
  int i;

  for (i = 0; i < n; i++) {
    curr = curr->next;
  }

  while (curr->next) {
    curr = curr->next;
    prev = prev->next;
  }

  curr = prev->next;
  prev->next = curr->next;
  delete curr;

  return head;
}
