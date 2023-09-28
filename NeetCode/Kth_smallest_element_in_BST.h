#include <iostream>
#include <stack>
#include <stdio.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x, TreeNode* l, TreeNode* r): val(x), left(l), right(r) {}
};

void inorder(TreeNode* root, stack<TreeNode*> &nodes, int &k) {
  if(!root) {
    return;
  }
  nodes.push(root);
  inorder(root->left, nodes, k);
  k--;
  if(k <= 0) {
    return;
  }
  nodes.pop();
  if(root->right) {
    inorder(root->right, nodes, k);
  }
}

int kth_smallest(TreeNode* root, int k) {
  stack<TreeNode*> nodes;  
  inorder(root, nodes, k);
  return nodes.top()->val;
}
