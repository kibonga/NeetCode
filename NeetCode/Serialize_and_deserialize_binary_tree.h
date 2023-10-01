#include <iostream>
#include <sstream>
#include <string>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x, TreeNode* l, TreeNode* r): val(x), left(l), right(r) {}
};

void encode(TreeNode* root, ostringstream& stream) {
  if(!root) {
    stream << "N";
    return;
  }

  stream << root->val;
  encode(root->left, stream);
  encode(root->right, stream);
}

TreeNode* decode(string data, int& i) {
  char ch = data[i];
  i++;

  if(ch == 'N') {
    return nullptr;
  }

  int x = ch - '0';

  TreeNode* root = new TreeNode(x, nullptr, nullptr);

  root->left = decode(data, i);
  root->right = decode(data, i);

  return root;
}

string serialize(TreeNode* root) {
  ostringstream stream;
  encode(root, stream);
  return stream.str();
}

TreeNode* deserialize(string data) {
  int i = 0;
  return decode(data, i);
}

void preorder(TreeNode* root) {
  if(!root) {
    return;
  }

  cout << root->val << " ";
  preorder(root->left);
  preorder(root->right);
}
