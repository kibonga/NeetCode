// NeetCode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Add_two_numbers.h"

int main()
{
    ListNode* num1_4 = new ListNode(1);
    ListNode* num1_3 = new ListNode(2);
    ListNode* num1_2 = new ListNode(4);
    ListNode* num1_1 = new ListNode(3);
    
    ListNode* num2_3 = new ListNode(5);
    ListNode* num2_2 = new ListNode(6);
    ListNode* num2_1 = new ListNode(4);

    num1_4->next = num1_3;
    num1_3->next = num1_2;
    num1_2->next = num1_1;

    num2_3->next = num2_2;
    num2_2->next = num2_1;
   
    display(num1_4);
    display(num2_3);
    auto num3 = add_two_numbers(num2_3, num1_4);
    display(num3);

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
