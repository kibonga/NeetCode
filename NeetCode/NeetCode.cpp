// NeetCode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Kth_smallest_element_in_BST.h"

int main()
{
  TreeNode* tn1 = new TreeNode(1, nullptr, nullptr);
  TreeNode* tn2 = new TreeNode(2, tn1, nullptr);
  TreeNode* tn4 = new TreeNode(4, nullptr, nullptr);
  TreeNode* tn3 = new TreeNode(3, tn2, tn4);
  TreeNode* tn6 = new TreeNode(6, nullptr, nullptr);
  TreeNode* tn5 = new TreeNode(5, tn3, tn6);

  int k = 3;
  int result = kth_smallest(tn5, k);
  cout << "Kth smallest = " << result << endl;
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
