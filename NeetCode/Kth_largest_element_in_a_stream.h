#include <functional>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct KthLargest {
  int k;
  priority_queue<int, vector<int>, greater<int>> pq;
  KthLargest(int k, vector<int>& nums) {
    k = k;
    for(int i=0; i<nums.size(); i++) {
      pq.push(nums[i]);
    }
    while(pq.size() > k) {
      pq.pop();
    }
  }
};

int add(KthLargest* kth, int val) {
  kth->pq.push(val);
  if(kth->pq.size() > kth->k) {
    kth->pq.pop();
  }
  return kth->pq.top();
}
