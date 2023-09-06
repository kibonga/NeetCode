#include <iostream>
#include <stdio.h>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode* prev;
  ListNode(int x) : val(x), next(nullptr), prev(nullptr) {}
};

ListNode* swap_pairs(ListNode* head) {
  if(!head) {
    cout << "List is empty" << endl;
    return head;
  }
  if(!head->next) {
    cout << "There is only one element in list" << endl;
    return head;
  }

  ListNode* ln1 = head;
  ListNode* ln2 = head->next;
  ListNode* prev = nullptr;
  ListNode* next = nullptr;

  while(ln1 && ln2) {
    if(prev) {
      prev->next = ln2;
    }
    else {
      head = ln2;
      prev = ln1;
    }
    next = ln2->next;
    ln2->next = ln1;
    ln1->next = next; 

    prev = ln1;
    ln1 = next;
    if(next) {
      ln2 = next->next;
    }
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
