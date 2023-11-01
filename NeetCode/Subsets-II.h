#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<int>& nums, int start, vector<int>& curr, vector<vector<int>>& result) {
  result.push_back(curr);

  for(int i=start; i<nums.size(); i++) {

    if(i > start && (nums[i] == nums[i-1])) {
      continue;
    }

    curr.push_back(nums[i]);
    dfs(nums, i+1, curr, result);
    curr.pop_back();
  }

}

void subsets(vector<int>& nums, vector<vector<int>>& result) {
  sort(nums.begin(), nums.end());
  vector<int> curr;
  dfs(nums, 0, curr, result);
}
