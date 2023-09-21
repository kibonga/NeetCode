#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x, TreeNode* l, TreeNode* r): val(x), left(l), right(r) {}
};

void level_order(TreeNode* root) {
  if(!root) {
    cout << "Tree is empty";
    return;
  }

  queue<TreeNode**> nodes;
  nodes.push(&root);

  TreeNode* t;
  cout << "Level order = ";
  do {
    t = *nodes.front();
    nodes.pop();
    cout << t->val << " ";
    if(t->left) {
      nodes.push(&t->left);
    }
    if(t->right) {
      nodes.push(&t->right);
    }
  } while (!nodes.empty());
  cout << endl;
}

