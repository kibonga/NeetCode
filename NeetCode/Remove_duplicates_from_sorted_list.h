#include <iostream>
#include <stdio.h>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode* prev;
  ListNode(int x) : val(x), next(nullptr), prev(nullptr) {}
};

ListNode* remove_duplicates(ListNode* head) {
  ListNode* temp = head->next;
  ListNode* curr = head;
  ListNode* remove = nullptr;
  
  while(temp) {
    if(temp->val == curr->val) {
      remove = temp;
      temp = temp->next;
      curr->next = temp;
      delete remove;
      continue;
    }
    curr = temp;
    temp = temp->next;
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
