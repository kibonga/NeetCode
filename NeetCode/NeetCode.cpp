// NeetCode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Invert_binary_tree.h"

int main()
{
  TreeNode* t1 = new TreeNode(4);
  TreeNode* t2 = new TreeNode(2);
  TreeNode* t3 = new TreeNode(7);
  TreeNode* t4 = new TreeNode(1);
  TreeNode* t5 = new TreeNode(3);
  TreeNode* t6 = new TreeNode(6);
  TreeNode* t7 = new TreeNode(9);

  t1->left = t2;
  t1->right = t3;
  t2->left = t4;
  t2->right = t5;
  t3->left = t6;
  t3->right = t7;

  std::cout << "Tree= ";
  display(t1);
  std::cout << std::endl;
  TreeNode* res = invert_tree(t1);
  std::cout << "Tree= ";
  display(res);
  std::cout << std::endl;
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
