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

int max_height(TreeNode* root, int& diameter) {
  if (!root) {
    return 0;
  }

  int left_height = max_height(root->left, diameter);
  int right_height = max_height(root->right, diameter);

  if((left_height + right_height) > diameter) {
    diameter = left_height + right_height;
  }

  return max(left_height, right_height) + 1;
}

int tree_diameter(TreeNode* root) {
  int diameter = 0;
  max_height(root, diameter);
  return diameter;
}
