// NeetCode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <cstddef>
#include <iostream>
#include "Validate_bst.h"

int main()
{
  // TreeNode* tn3 = new TreeNode(3, nullptr, nullptr);
  // TreeNode* tn6 = new TreeNode(6, nullptr, nullptr);
  // TreeNode* tn1 = new TreeNode(1, nullptr, nullptr);
  // TreeNode* tn4 = new TreeNode(4, tn3, tn6);
  // TreeNode* tn5 = new TreeNode(5, tn1, tn4);

  TreeNode* tn3 = new TreeNode(3, nullptr, nullptr);
  TreeNode* tn7 = new TreeNode(7, nullptr, nullptr);
  TreeNode* tn1 = new TreeNode(1, nullptr, nullptr);
  TreeNode* tn6 = new TreeNode(6, tn3, tn7);
  TreeNode* tn5 = new TreeNode(5, tn1, tn6);

  bool res = is_valid_bst(tn5);
  cout << "Valid = " << res << endl;
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
