#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<int>& nums, vector<vector<int>>& result, vector<int>& curr, int start) {

  if(start == nums.size()) {
    result.push_back(nums);
    return;
  }

  for(int i=start; i<nums.size(); i++) {
    swap(nums[i], nums[start]);
    dfs(nums, result, curr, start+1);
    swap(nums[i], nums[start]);
  }

}

void permute(vector<int>& nums, vector<vector<int>>& result) {
  vector<int> curr; 
  dfs(nums, result, curr, 0);
}

