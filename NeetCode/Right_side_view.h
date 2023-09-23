#include <cmath>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x, TreeNode* l, TreeNode* r): val(x), left(l), right(r) {}
};

void right_side_view(TreeNode* root) {
  if(!root) {
    cout << "Tree is empty";
    return;
  }

  queue<TreeNode**> q;
  vector<int> vec; 

  q.push(&root);

  TreeNode* t = nullptr;
  TreeNode* emptyNode = new TreeNode(-1, nullptr, nullptr);
  do {
    t = *q.front();

    if(t->val == -1) {
      vec.push_back(0);
    } else {
      vec.push_back(t->val);
    }

    q.pop();
    if(t->left) {
      q.push(&t->left);
    }else if((t->left || t->right) && t->val != -1){
      q.push(&emptyNode);
    }

    if(t->right) {
      q.push(&t->right);
    }else if((t->left || t->right) && t->val != -1){
      q.push(&emptyNode);
    }
  }while (!q.empty());

  int j = 0;
  int levels = static_cast<int>(std::ceil(std::log2(vec.size() + 1)));
  for(int i=0; i < levels; i++) {
    j += pow(2, i);
    for(int n=j-1; n>=j-pow(2,i); n--) {
      if(vec[n] == 0) {
        continue;
      }
      cout << vec[n] << " ";
      break;
    }
  }
}
