#include <iostream>
#include <stdio.h>
using namespace std;

struct TreeNode {
  int val; 
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x, TreeNode* l, TreeNode* r): val(x), left(l), right(r) {}
};

void inorder(TreeNode* root, int &k, int &result) {
  if(!root) {
    return;
  } 

  inorder(root->left, k, result);
  k--;
  if(k == 0) {
    result = root->val;
    return;
  }
  inorder(root->right, k, result);
}

int kth_smallest(TreeNode* root, int &k) {
  int result = 0;
  inorder(root, k, result);
  return result;
}
