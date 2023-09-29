#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x, TreeNode* l, TreeNode* r): val(x), left(l), right(r) {}
  TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& index, int i, int j) {
  if(i > j) {
    return nullptr;
  }

  TreeNode* root = new TreeNode(preorder[index]);

  int split = 0;
  for(int i=0; i<inorder.size(); i++) {
    if(preorder[index] == inorder[i]) {
      split = i;
      break;
    }
  }
  index++;

  root->left = build(preorder, inorder, index, i, split - 1);
  root->right = build(preorder, inorder, index, split + 1, j);

  return root;
}

TreeNode* build_tree(vector<int>& preorder, vector<int>& inorder) {
  int index = 0;
  return build(preorder, inorder, index, 0, inorder.size() - 1);
}

void preorder(TreeNode* root) {
  if(!root) {
    return;
  }
  cout << root->val << " ";
  preorder(root->left);
  preorder(root->right);
}
