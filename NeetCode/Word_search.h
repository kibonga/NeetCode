#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

struct TrieNode {
  bool isWord;
  TrieNode* children[26];
  TrieNode(): isWord(false) {
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
    node = node->children[c-'a'];
  }
  node->isWord = true;
}

void search(vector<vector<char>>& board, TrieNode* node, int i, int j, stringstream& ss, vector<string>& result) {
  
  int m = board.size();
  int n = board.front().size();

  if( (i < 0) || (i >= m) || (j < 0) || (j >= n) || board[i][j] == '#') {
    return; 
  }

  char c = board[i][j];
  node = node->children[c-'a'];

  if(!node) {
    return;
  }

  ss << c;

  if(node->isWord) {
    result.push_back(ss.str());
    node->isWord = false;
  }

  board[i][j] = '#';

  search(board, node, (i-1), j, ss, result);
  search(board, node, (i+1), j, ss, result);
  search(board, node, i, (j-1), ss, result);
  search(board, node, i, (j+1), ss, result);

  board[i][j] = c;
}

vector<string> find_words(vector<vector<char>>& board, vector<string>& words) {
  TrieNode node = TrieNode();
  vector<string> result;
  
  for(auto& w : words) {
    add(&node, w);
  }

  int m = board.size();
  int n = board.front().size();

  for(int i=0; i<m; i++) {
    for(int j=0; j<n; j++) {
      stringstream ss;
      search(board, &node, i, j, ss, result);
    }
  }

  return result;
}
