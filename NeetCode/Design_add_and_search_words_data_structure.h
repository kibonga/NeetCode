#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

struct TrieNode {
  string word;
  int isWord;
  TrieNode* children[26];
  TrieNode(): word(""), isWord(false) {
    for(int i=0; i<26; i++) {
      children[i] = nullptr;
    }
  }
};

void add(TrieNode* node, string& word) {
  for(auto& c : word) {
    if(!node->children[c-'a']) {
      node->children[c-'a'] = new TrieNode();
    }
    node = node->children[c-'a']; }
  node->word = word;
  node->isWord = 1;
}

int search_node(TrieNode* node, string& word, int i) {
  if(!node) {
    return 0;
  }

  if(i == word.size()) {
    return node->isWord;
  }

  char c = word[i];

  bool search_result = false;
  if(c == '.') {
    for(int j=0; j<26; j++) {
      search_result = search_node(node->children[j], word, i+1);
      if(search_result) {
        return true;
      }
    }
  }

  return search_node(node->children[c-'a'], word, i+1);
}

int search(TrieNode* node, string& word) {
  return search_node(node, word, 0); 
}
