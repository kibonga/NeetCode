// NeetCode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Same_tree.h"

int main()
{
  TreeNode* l2 = new TreeNode(2, nullptr, nullptr);
  TreeNode* l3 = new TreeNode(3, nullptr, nullptr);
  TreeNode* l1 = new TreeNode(1, l2, l3);

  TreeNode* r2 = new TreeNode(2, nullptr, nullptr);
  TreeNode* r3 = new TreeNode(3, nullptr, nullptr);
  TreeNode* r1 = new TreeNode(1, r2, r3);

  cout << "Result = " << is_same_tree(l1, r1) << endl;
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
