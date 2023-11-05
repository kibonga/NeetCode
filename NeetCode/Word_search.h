#include <cstddef>
#include <iostream>
#include <tuple>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

struct tuple_hash {
  size_t operator()(const tuple<int, int>& tp) const {
    auto [a, b] = tp;
    return hash<int>()(a) ^ hash<int>()(b << 10);
  }
};

bool dfs(vector<vector<char>>& board, string word, unordered_map<tuple<int, int>, bool, tuple_hash>& umap, int row, int col, int start) {

  auto tp = make_tuple(row, col);
  

  if( row < 0 || 
      col < 0 ||
      row >= board.size() ||
      col >= board[0].size()
  ) {
    return false;    
  }

  char w = word[start];
  char c = board[row][col];
  bool isNotChar = word[start] != board[row][col];
  bool exists = umap.find(tp) != umap.end();
  if(isNotChar || exists) {
    return false;
  }


  if(start == word.size() - 1) {
    return true;
  }

  umap.insert({tp, true});

  bool res =
      dfs(board, word, umap, row + 1, col, start + 1) ||
      dfs(board, word, umap, row - 1, col, start + 1) ||
      dfs(board, word, umap, row, col + 1, start + 1) ||
      dfs(board, word, umap, row, col - 1, start + 1);

  umap.erase(tp);

  return res;
}

bool word_search(vector<vector<char>>& board, string word) {
  int row_size = board.size();
  int col_size = board[0].size();
  unordered_map<tuple<int, int>, bool, tuple_hash> umap;

  for(int i=0; i<row_size; i++) {
    for(int j=0; j<col_size; j++) {
      if(dfs(board, word, umap, i, j, 0)) {
        return true;
      }
    }
  }

  return false;
}

bool backtrack(vector<vector<char>>& board, string& word, int row_size, int col_size, int row, int col, int start) {

  if( row < 0 ||
      col < 0 ||
      row >= row_size ||
      col >= col_size ||
      board[row][col] == '#' ||
      word[start] != board[row][col]
  ) {
    return false;
  }

  if(start == word.size() - 1) {
    return true;
  }

  char c = board[row][col];

  board[row][col] = '#';

  bool result = 
    backtrack(board, word, row_size, col_size, row + 1, col, start + 1) ||
    backtrack(board, word, row_size, col_size, row - 1, col, start + 1) ||
    backtrack(board, word, row_size, col_size, row, col + 1, start + 1) ||
    backtrack(board, word, row_size, col_size, row, col - 1, start + 1);

  board[row][col] = c;

  return result;
}

bool word_search2(vector<vector<char>>& board, string word) {
  int row_size = board.size(); 
  int col_size = board[0].size();

  for(int i=0; i<row_size; i++) {
    for(int j=0; j<col_size; j++) {
      if(backtrack(board, word, row_size, col_size, i, j, 0)) {
        return true;
      }
    }
  }

  return false;
}
