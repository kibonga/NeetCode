#include <iostream>
#include <vector>
using namespace std;

void helper(int target, int start, vector<int>& curr, vector<int>& candidates, vector<vector<int>>& result) {

  if(start >= candidates.size() || target < 0) {
    return;
  }

  if(target == 0) {
    result.push_back(curr);
    return;
  }

  curr.push_back(candidates[start]);

  helper((target - candidates[start]), start, curr, candidates, result); 

  curr.pop_back();

  helper(target, (start + 1), curr, candidates, result);
}

void combination_sum(int target, vector<int>& candidates, vector<vector<int>>& result) {
  vector<int> curr;  
  helper(target, 0, curr, candidates, result);
}

