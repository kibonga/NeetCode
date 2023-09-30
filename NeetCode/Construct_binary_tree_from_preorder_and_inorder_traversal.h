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

TreeNode* build(vector<int>& preorder, vector<int>& inorder, int pre_start, int in_start, int in_end) {

  if((pre_start > (preorder.size() - 1)) || (in_start > in_end)) {
    return nullptr;
  }

  TreeNode* root = new TreeNode(preorder[pre_start]);

  int mid;
  for(int i = 0; i < inorder.size(); i++) {
    if(preorder[pre_start] == inorder[i]) {
      mid = i; 
      break;
    }
  }

  root->left = build(preorder, inorder, (pre_start + 1), in_start, (mid - 1));
  root->right = build(preorder, inorder, (pre_start + mid - in_start + 1), (mid + 1), in_end);

  return root;
}

TreeNode* build_tree(vector<int>& preorder, vector<int>& inorder) {
  return build(preorder, inorder, 0, 0, inorder.size() - 1);
}

void preorder(TreeNode* root) {
  if(!root) {
    return;
  }
  cout << root->val << " ";
  preorder(root->left);
  preorder(root->right);
}
