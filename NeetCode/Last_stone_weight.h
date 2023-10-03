#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int last_stone_weight(vector<int>& stones) {
  priority_queue<int> pq;
  for(int i=0; i<stones.size(); i++) {
    pq.push(stones[i]);
  }
  int a, b;
  while(!pq.empty() && pq.size() > 1) {
    a = pq.top();
    pq.pop();
    b = pq.top();
    pq.pop();

    if(a == b) {
      continue;
    }

    if(a > b) {
      pq.push(a - b);
    }else {
      pq.push(b - a);
    }

  } 

  return pq.top();
}
