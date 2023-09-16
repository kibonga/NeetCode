#include <cmath>
#include <iostream>
#include <stdio.h>
#include <valarray>
using namespace std;


struct Balance {
  int height;
  bool isBalanced;
  Balance(): height(-1), isBalanced(true) {}
  // Balance(int x, bool y): height(x), isBalanced(y) {}
};

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  Balance balance;
  TreeNode(int x, TreeNode* l, TreeNode* r): val(x), left(l), right(r) {}
};

void subtree_balance(TreeNode* root) {
 if(!root) {
    // root->balance.height = 0;
    // root->balance.isBalanced = true;
    return;
  }

  subtree_balance(root->left);
  subtree_balance(root->right);

  int leftHeight = (root->left) ? root->left->balance.height : 0;
  int rightHeight = (root->left) ? root->right->balance.height : 0;

  int height = max(leftHeight, rightHeight) + 1;
  int diff = abs(leftHeight - rightHeight);

  root->balance.height = height;

  if((root->left && (!root->left->balance.isBalanced)) || 
    (root->right && (!root->right->balance.isBalanced)) || 
    diff >= 2
  ) {
    root->balance.isBalanced = false;
    return;
  } 
}

bool is_tree_balanced(TreeNode* root) {
  subtree_balance(root);  
  return root->balance.isBalanced;
}


