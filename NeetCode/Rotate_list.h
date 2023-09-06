#include <iostream>
#include <stdio.h>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode* prev;
  ListNode(int x) : val(x), next(nullptr), prev(nullptr) {}
};

ListNode* rotate(ListNode* head, int k) {
  ListNode* curr = head;
  ListNode* tail = nullptr;
  int size = 0;
  while(curr) {
    size++;
    tail = curr;
    curr = curr->next;
  }
  int n;
  if(k < 0) {
    n = (-(k % size)) - 1;
  }else {
    n = size - (k % size) - 1;
  }
  curr = head;
  for(int i=0; i<n; i++) {
    curr = curr->next;
  }

  if(k < 0) {
    tail->next = head;
    head = curr->next;
    curr->next = nullptr;
  }
  else {
    tail->next = head;
    head = curr->next;
    curr->next = nullptr;
    tail = curr;
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
