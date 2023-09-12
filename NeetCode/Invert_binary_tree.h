#include <cwchar>
#include <fstream>
#include <iostream>
#include <stdio.h>

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* invert_tree(TreeNode* root) {
  if(!root) { 
    return nullptr;
  } 
  std::swap(root->left, root->right);
  invert_tree(root->left);
  invert_tree(root->right);
  return root;
}

void display(TreeNode* root) {
  if(!root) {
    return;
  }
  std::cout << root->val << " ";
  display(root->left);
  display(root->right);
}
