// NeetCode.cpp : This file contains the 'main' function. Program execution
// begins and ends there.
//

#include "Merge_two_sorted_lists.h"
#include <iostream>

int main() {
  LinkedList *linked_list = new LinkedList();
  LinkedList *linked_list2 = new LinkedList();
  linked_list->add(1);
  linked_list->add(3);
  linked_list->add(5);
  linked_list->display();
  linked_list2->add(2);
  linked_list2->add(4);
  linked_list2->add(6);
  linked_list2->display();
  linked_list->merge(linked_list2->head);
  linked_list->display();
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
