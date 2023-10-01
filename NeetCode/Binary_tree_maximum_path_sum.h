#include <iostream>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x, TreeNode* l, TreeNode* r): val(x), left(l), right(r) {}
};

int max(int a, int b) {
  return a > b ? a : b;
}

int max_path(TreeNode* root, int& result) {
  if(!root) {
    return 0;
  } 

  int left_subtree = max_path(root->left, result);
  int right_subtree = max_path(root->right, result);

  int sum = left_subtree + right_subtree + root->val;

  if(sum > result) {
    result = sum;
  }

  if((left_subtree <= 0) && (right_subtree <= 0)) {
    return root->val;
  }

  return max(left_subtree, right_subtree) + root->val;
}

int max_path_sum(TreeNode* root) {
  int result = 0;
  max_path(root, result); // TODO
  return result;
}
