#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<int>& candidates, vector<vector<int>>& result, int target, vector<int>& curr, int start) {

  if(target < 0 || start >= candidates.size()) {
    return;
  }
  
  if(target == 0) {
    result.push_back(curr);
    return;
  }

  curr.push_back(candidates[start]);
  dfs(candidates, result, (target-candidates[start]), curr, start);

  curr.pop_back();
  dfs(candidates, result, target, curr, start + 1);

}

void combination_sum(vector<int>& candidates, vector<vector<int>>& result, int target) {
  vector<int> curr; 
  dfs(candidates, result, target, curr, 0);
}

