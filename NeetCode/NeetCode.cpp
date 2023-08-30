// NeetCode.cpp : This file contains the 'main' function. Program execution
// begins and ends there.
//

#include "Remove_nth_node_from_end_of_the_list.h"
#include <iostream>

int main() {
  ListNode *head = new ListNode(1);
  ListNode *node2 = new ListNode(2);
  ListNode *node3 = new ListNode(3);
  ListNode *node4 = new ListNode(4);
  ListNode *node5 = new ListNode(5);
  ListNode *node6 = new ListNode(6);
  ListNode *node7 = new ListNode(7);
  ListNode *node8 = new ListNode(8);
  ListNode *node9 = new ListNode(9);
  ListNode *node10 = new ListNode(10);
  ListNode *node11 = new ListNode(11);
  head->next = node2;
  node2->next = node3;
  node3->next = node4;
  node4->next = node5;
  node5->next = node6;
  node6->next = node7;
  node7->next = node8;
  node8->next = node9;
  node9->next = node10;
  node10->next = node11;

  ListNode *result = remove_nth_from_end(head, 3);
  display(result);
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
