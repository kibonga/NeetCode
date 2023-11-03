#include <iostream>
#include <type_traits>
using namespace std;

struct TreeNode {
  TreeNode* left;
  int val;
  TreeNode* right;
  TreeNode(int v, TreeNode* l, TreeNode* r): val(v), left(l), right(r) {}
};

bool is_same_tree(TreeNode* a, TreeNode* b) {
  if(!a && !b) {
    return true;
  }

  if(!a || !b) {
    return false;
  }

  if(a->val != b->val) {
    return false;
  }


  return is_same_tree(a->left, b->left) && is_same_tree(a->right, b->right);
}

