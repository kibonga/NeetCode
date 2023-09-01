// NeetCode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Reorder_list.h"

int main()
{
    LinkedNode* node1 = new LinkedNode(1);
    LinkedNode* node2 = new LinkedNode(2);
    LinkedNode* node3 = new LinkedNode(3);
    LinkedNode* node4 = new LinkedNode(4);
    LinkedNode* node5 = new LinkedNode(5);
    LinkedNode* node6 = new LinkedNode(6);
    
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;

    display(node1);
    auto head = reorder(node1);
    display(head);
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
