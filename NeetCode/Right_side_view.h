#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x, TreeNode* l, TreeNode* r): val(x), left(l), right(r) {}
};

void right_side_view(TreeNode* root) {
  if(!root) {
    cout << "Tree is empty" << endl;
    return;
  } 

  vector<int> vec;
  queue<TreeNode*> nodes;

  nodes.push(root);
  TreeNode* temp = nullptr;

  while(!nodes.empty()) {
    int n = nodes.size();

    for(int i=0; i<n; i++) {
      temp = nodes.front();
      nodes.pop();
      
      if(i == (n-1)) {
        vec.push_back(temp->val);
      }

      if(temp->left) {
        nodes.push(temp->left);
      }

      if(temp->right) {
        nodes.push(temp->right);
      }
    }  
  }

  cout << "Right side = ";
  for(auto v : vec) {
    cout << v << " ";
  }
}
