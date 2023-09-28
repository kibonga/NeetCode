#include <stack>
#include <stdio.h>
#include <iostream>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x, TreeNode* l, TreeNode* r): val(x), left(l), right(r) {}
};

int kth_smallest(TreeNode* root, int k) {
  int result;
  stack<TreeNode*> nodes;

  TreeNode* curr = root;
  
  while(curr || !nodes.empty()) {
    while(curr) {
      nodes.push(curr);
      curr = curr->left;
    }
    k--;
    curr = nodes.top();
    if(k <= 0) {
      break;
    }
    nodes.pop();
    curr = curr->right;
   }

  return nodes.top()->val;
}
