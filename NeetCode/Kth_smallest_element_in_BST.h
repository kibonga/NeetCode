#include <iostream>
#include <queue>
#include <stack>
#include <stdio.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x, TreeNode* l, TreeNode* r): val(x), left(l), right(r) {}
};

TreeNode* inorder(TreeNode* root, queue<TreeNode*> &nodes) {
  if(!root) {
    return nullptr;
  }

  TreeNode* left = inorder(root->left, nodes);
  if(left) {
    nodes.push(left);
  }
  nodes.push(root);
  return inorder(root->right, nodes);
}

int kth_smallest(TreeNode* root, int k) {
  queue<TreeNode*> nodes;
  TreeNode* result = inorder(root, nodes); 

  while(!nodes.empty() && k > 1) {
    nodes.pop();
    k--;
  }
  return nodes.front()->val;
}
