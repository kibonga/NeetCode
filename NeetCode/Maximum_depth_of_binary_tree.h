#include <algorithm>
#include <iostream>
#include <stdio.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x, TreeNode* l, TreeNode* r): val(x), left(l), right(r) {}
};

int max(int a, int b) {
  return (a > b) ? a : b;
}

int max_depth(TreeNode* root) {
  if(!root) {
    return 0;
  } 

  return max(max_depth(root->left), max_depth(root->right)) + 1;
}
