#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void dfs(vector<vector<int>>& result, vector<int>& candidates, vector<int>& curr, int target, int start) {

  if(start >= candidates.size() || target < 0) {
    return;
  }

  if(target == 0) {
    result.push_back(curr);
  }

  for(int i=start; i<candidates.size(); i++) {

    if(i > start && candidates[i] == candidates[i-1]) {
      continue;
    }

    curr.push_back(candidates[i]);
    dfs(result, candidates, curr, (target-candidates[i]), i+1);
    curr.pop_back();
  }
  
}

void combination_sum(vector<vector<int>>& result, vector<int>& candidates, int target) {
  vector<int> curr;
  sort(candidates.begin(), candidates.end());
  dfs(result, candidates, curr, target, 0);
}
