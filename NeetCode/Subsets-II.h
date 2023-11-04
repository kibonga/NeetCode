#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool equal(vector<int>& a, vector<int>& b) {

  if(a.size() != b.size()) {
    return false;   
  }

  int size = a.size();

  for(int i=0; i<size; i++) {
    if(a[i] != b[i]) {
      return false;
    }
  }

  return true;
}

void dfs(vector<int>& nums, vector<vector<int>>& result, vector<int>& curr, int start) {
  
  bool areSame;
  for(auto res : result) {
    areSame = equal(res, curr); 
    if(areSame) {
      return;
    }
  }

  result.push_back(curr);

  for(int i=start; i<nums.size(); i++) {
    curr.push_back(nums[i]);
    dfs(nums, result, curr, i+1);
    curr.pop_back();
  }

}

void backtrack(vector<int>& nums, vector<vector<int>>& result, vector<int>& curr, int start) {
  
  result.push_back(curr);

  for(int i=start; i<nums.size(); i++) {

    if(i > start && nums[i] == nums[i-1]) {
      continue;
    }

    curr.push_back(nums[i]);

    backtrack(nums, result, curr, i+1);

    curr.pop_back();
  }

}

void unique_subsets(vector<int>& nums, vector<vector<int>>& result) {
  vector<int> curr; 
  sort(nums.begin(), nums.end());
  backtrack(nums, result, curr, 0);
  // dfs(nums, result, curr, 0);
}
