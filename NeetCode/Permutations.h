#include <iostream>
#include <vector>
using namespace std;

void helper(int start, vector<int>& nums, vector<vector<int>>& result) {

  if(start == nums.size()) {
    result.push_back(nums);
    return;
  }

  for(int i=start; i<nums.size(); i++) {
    swap(nums[i], nums[start]);
    helper(start + 1, nums, result);
    swap(nums[1], nums[start]);
  }
}

void permute(vector<int>& nums, vector<vector<int>>& result) {
  helper(0, nums, result);
}

