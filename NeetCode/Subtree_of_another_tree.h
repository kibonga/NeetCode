#include <stdio.h>
#include <iostream>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x, TreeNode* l, TreeNode* r): val(x), left(l), right(r) {}
};

bool is_same_tree(TreeNode* p, TreeNode* q) {
  if(!p && !q) {
    return true;
  }

  if((p && !q) || (!p && q)) {
    return false;
  }

  if(p->val != q->val) {
    return false;
  }

  return is_same_tree(p->left, q->left) && is_same_tree(p->right, q->right);
}

bool is_subtree(TreeNode* root, TreeNode* sub_root) {
  if(!root) {
    return false;
  }

  bool are_same = false;
  if(root->val == sub_root->val) {
      are_same = is_same_tree(root, sub_root);
  }

  return is_subtree(root->left, sub_root) || 
          is_subtree(root->right, sub_root) || 
          are_same;
}
