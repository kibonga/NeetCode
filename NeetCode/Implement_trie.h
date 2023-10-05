#include <iostream>
#include <vector>
using namespace std;

struct TrieNode {
  string word;
  bool isWord;
  vector<TrieNode*> children;
  TrieNode() : word(""), isWord(false), children(26, nullptr) {};
};

void insert(TrieNode* node, string word) {
  for(auto& w : word) {
    if(!node->children[w-'a']) {
      node->children[w-'a'] = new TrieNode();
    }
    node = node->children[w-'a'];
  }
  node->word = word; 
  node->isWord = 1;
}

bool search(TrieNode* node, string word) {
  for(auto& w : word) {
    if(!node->children[w-'a']) {
      return false;
    }
    node = node->children[w-'a'];
  }
  return node->isWord;
}

bool starts_with(TrieNode* node, string word) {
  for(auto& w : word) {
    if(!node->children[w-'a']) {
      return false;
    }
    node = node->children[w-'a'];
  }
  return true;
}
