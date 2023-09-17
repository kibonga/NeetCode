// NeetCode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Maximum_depth_of_binary_tree.h"

int main()
{
  TreeNode* tn15 = new TreeNode(15, nullptr, nullptr);
  TreeNode* tn7 = new TreeNode(7, nullptr, nullptr);

  TreeNode* tn9 = new TreeNode(9, nullptr, nullptr);
  TreeNode* tn20 = new TreeNode(20, tn15, tn7);

  TreeNode* tn3 = new TreeNode(3, tn9, tn20);

  int res = max_depth(tn3);
  cout << "Max depth = " << res << endl;
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
