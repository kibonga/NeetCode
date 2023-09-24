#include <cstdint>
#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x, TreeNode* l, TreeNode* r): val(x), left(l), right(r) {}
};

// int count_good_nodes(TreeNode* root) {
//   if(!root) {
//     cout << "Tree is empty" << endl;
//     return -1;
//   }
//
//   queue<TreeNode*> nodes;
//   nodes.push(root);
//   int result = 0;
//   int max = root->val;
//   int level_max = max;
//   
//   TreeNode* curr = nullptr;
//   while(!nodes.empty()) {
//     int n = nodes.size();
//
//     for(int i=0; i<n; i++) {
//       curr = nodes.front(); 
//       nodes.pop(); 
//
//       if(curr->val <= max) {
//         result++;
//       }
//
//       if(curr->left) {
//         nodes.push(curr->left);
//       }
//       if(curr->right) {
//         nodes.push(curr->right);
//       } 
//     }
//   }
// }

void is_good(TreeNode* root, int max_ancestor, int &result) {
  if(!root) {
    return;
  }

  if(root->val >= max_ancestor) {
    result++;
    max_ancestor = root->val;
  }


  is_good(root->left, max_ancestor, result);
  is_good(root->right, max_ancestor, result);
}

int good_nodes(TreeNode* root) {
  if(!root) {
    cout << "Tree is empty" << endl;
    return -1;
  }
  
  int result = 0;
  int max_ancestor = root->val;

  is_good(root, max_ancestor, result);

  return result;
}

