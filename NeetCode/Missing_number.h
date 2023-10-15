#include <iostream>
#include <vector>
using namespace std;

int missing_number(vector<int>& nums) {
  int n = nums.size();
  int result = n;

  for(int i=0; i<n; i++) {
    result ^= i ^ nums[i];
  }

  return result;
}

