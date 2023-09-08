#include <iostream>
#include <stdio.h>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode* prev;
  ListNode(int x) : val(x), next(nullptr), prev(nullptr) {} 
};

ListNode* delete_duplicates(ListNode* head) {
  if(!head) {
    cout << "List is empty" << endl;
    return head;
  }
  ListNode* prev = nullptr;
  ListNode* curr = head;
  ListNode* next = head->next; 

  while(curr && next) {
    if(curr->val != next->val) {
      prev = curr;
      curr = curr->next;
      next = curr->next;
      continue;
    }

    int val = curr->val;
    while(next && (next->val == val)) {
      delete curr;
      curr = next;
      next = next->next;
    }
    delete curr;
    if(!prev) {
      prev = next;
      head = next;
    }
    else {
      prev->next = next;
    }

    if(!next) {
      prev->next = nullptr;
      continue;
    }

    curr = next;
    next = curr->next;
  }

  return head;
}

void display(ListNode* head) {
  ListNode* curr = head;
  cout << "List = ";
  while(curr) {
    cout << curr->val << " ";
    curr = curr->next;
  }
  cout << endl;
}
