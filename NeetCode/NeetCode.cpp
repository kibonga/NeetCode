// NeetCode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Remove_duplicates_from_sorted_list_II.h"

int main()
{
  ListNode* n1 = new ListNode(1);
  ListNode* n11 = new ListNode(1);
  ListNode* n2 = new ListNode(2);
  ListNode* n3 = new ListNode(3);
  ListNode* n33 = new ListNode(3);
  ListNode* n4 = new ListNode(4);
  ListNode* n44 = new ListNode(4);
  ListNode* n5 = new ListNode(5);
  ListNode* n55 = new ListNode(5);

  n1->next = n11;
  n11->next = n2;
  n2->next = n3;
  n3->next = n33;
  n33->next = n4;
  n4->next = n44;
  n44->next = n5;
  n5->next = n55;

  // ListNode* n1 = new ListNode(1);
  // ListNode* n11 = new ListNode(1);
  // ListNode* n111 = new ListNode(1);
  // ListNode* n2 = new ListNode(2);
  // ListNode* n3 = new ListNode(3);
  //
  // n1->next = n11;
  // n11->next = n111;
  // n111->next = n2;
  // n2->next = n3;

  display(n1);
  ListNode* res = delete_duplicates(n1);
  display(res);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
