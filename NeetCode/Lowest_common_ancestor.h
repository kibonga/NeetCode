#include <stdio.h>
#include <iostream>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x, TreeNode* l, TreeNode* r): val(x), left(l), right(r) {}
};

TreeNode* lowest_common_ancestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  if((p->val < root->val) && (q->val < root->val)) {
    return lowest_common_ancestor(root->left, p, q);
  }else if ((p->val > root->val) && (q->val > root->val)) {
    return lowest_common_ancestor(root, p, q);
  }else {
    return root;
  }
}
