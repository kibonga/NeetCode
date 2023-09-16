#include <cinttypes> 
#include <cstdlib>
#include <iostream>
#include <stdio.h>

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};

 bool is_subtree_balanced(TreeNode* root, int &height) {
  if(!root) {
    return 1;
  } 

  int leftHeight = 0, rightHeight = 0;

  bool leftSub = is_subtree_balanced(root->left, leftHeight);
  bool rightSub = is_subtree_balanced(root->right, rightHeight);

  int diff = abs(leftHeight - rightHeight);
  if(!leftSub || !rightSub || diff >= 2) {
    return false;
  }

  height = std::max(leftHeight, rightHeight) + 1;
  return true;
}

bool is_tree_balanced(TreeNode* root) {
  int height = 0;
  return is_subtree_balanced(root, height);
}
