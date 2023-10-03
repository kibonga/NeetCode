#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int find_kth_largest(vector<int>& nums, int k) {
  priority_queue<int> pq;

  for(auto& n : nums) {
    pq.push(n);
  }

  while(k-1 && k--) {
    pq.pop();
  }

  return pq.top();
}
