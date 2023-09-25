#include <stdio.h>
#include <iostream>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x, TreeNode* l, TreeNode* r): val(x), left(l), right(r) {}
};

bool is_valid_bst(TreeNode* root) {
  if(!root) {
    return true;
  }

  bool valid = true;
  if(root->left && (root->left->val > root->val)) {
    valid = false; 
  }
  if(root->right && (root->right->val < root->val)) {
    valid = false;
  }
  return valid && 
          is_valid_bst(root->left) && 
          is_valid_bst(root->right);
}
