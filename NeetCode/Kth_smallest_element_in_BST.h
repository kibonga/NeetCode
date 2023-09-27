#include <stdio.h>
#include <iostream>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x, TreeNode* l, TreeNode* r): val(x), left(l), right(r) {}
};

TreeNode* inorder(TreeNode* root, int &k) {
  if(!root->left) {
    k--;
    return root;
  }
  inorder(root->left, k);
  if(k <= 0) {
    return root->left;
  }
  k--;
  if(k <= 0) {
    return root;
  }
  if(root->right) {
    return inorder(root->right, k);
  }
  return root;
}

int kth_smallest(TreeNode* root, int &k) {
  TreeNode* result = inorder(root, k);
  return result->val;
}
