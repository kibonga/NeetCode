#include <iostream>
#include <vector>
using namespace std;

// bool is_palindrome(string& str) {
//   return equal(
//     str.begin(), 
//     (str.begin() + str.size() / 2),
//     str.rbegin());
// }

bool is_palindrome(string& word, int start, int end) {
  while(start < end) {
    if(word[start] != word[end]) {
      return false;
    }
    start++;
    end--;
  }

  return true;
}

void backtrack(vector<vector<string>>&result, string& word, int start, vector<string>& curr) {
  
  if(start == word.size()) {
    result.push_back(curr);
    return;
  }
  
  for(int i=start; i<word.size(); i++) {

    bool isPalindrome = is_palindrome(word, start, i);

    if(!isPalindrome) {
      continue;
    }

    string w = word.substr(start, i - start + 1);

    curr.push_back(w);

    backtrack(result, word, i + 1, curr); 

    curr.pop_back();

  }
  
}

void partition(vector<vector<string>>& result, string& word) {
  vector<string> curr;
  backtrack(result, word, 0, curr); 
}
