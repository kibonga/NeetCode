// NeetCode.cpp : This file contains the 'main' function. Program execution
// begins and ends there.
//

#include "Copy_list_with_random_pointer.h"
#include <iostream>

int main() {
  ListNode *node1 = new ListNode(7);
  ListNode *node2 = new ListNode(13);
  ListNode *node3 = new ListNode(11);
  ListNode *node4 = new ListNode(10);
  ListNode *node5 = new ListNode(1);

  node1->next = node2;
  node1->random = nullptr;

  node2->next = node3;
  node2->random = node1;

  node3->next = node4;
  node3->random = node5;

  node4->next = node5;
  node4->random = node3;

  node5->next = nullptr;
  node5->random = node1;

  display(node1);
  ListNode *head = deep_copy(node1);
  cout << endl << "======= Deep Copy =======" << endl << endl;
  display(head);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add
//   Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project
//   and select the .sln file
