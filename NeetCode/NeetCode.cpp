// NeetCode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Count_good_nodes_in_binary_tree.h"

int main()
{
  // TreeNode* tn3 = new TreeNode(3, nullptr, nullptr);    
  // TreeNode* tn1 = new TreeNode(1, nullptr, nullptr);    
  // TreeNode* tn5 = new TreeNode(5, nullptr, nullptr);    
  //
  // TreeNode* tn11 = new TreeNode(1, tn3, nullptr);    
  // TreeNode* tn4 = new TreeNode(4, tn1, tn5);    
  //
  // TreeNode* tn33 = new TreeNode(3, tn11, tn4);    
  //
  // int result = good_nodes(tn33);

  TreeNode* tn4 = new TreeNode(4, nullptr, nullptr);
  TreeNode* tn2 = new TreeNode(2, nullptr, nullptr);
  TreeNode* tn3 = new TreeNode(3, tn4, tn2);
  TreeNode* tn33 = new TreeNode(3, tn3, nullptr);

  int result = good_nodes(tn33);
  cout << "Good nodes = " << result << endl;
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
