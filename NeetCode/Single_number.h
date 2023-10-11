#include <iostream>
#include <vector>
using namespace std;

int single_number(vector<int>& nums) {
  int result = 0;
  for(int n : nums) {
    result = n ^ result;
  }
  return result;
}
