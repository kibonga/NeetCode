#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int least_interval(vector<char>& tasks, int n) {
  priority_queue<int> pq;
  queue<vector<int>>q;
  vector<int> counter(26);

  for(auto& t : tasks) {
    ++counter[t - 'A'];
  }

  for(auto& c : counter) {
    if(c) {
      pq.push(c);
    }
  }

  int time = 0;
  
  while(!q.empty() || !pq.empty()) {
    ++time;
    if(!pq.empty()) {
      if(pq.top() - 1) {
        q.push({pq.top() - 1, time + n});
      }
      pq.pop();
    }
    if(!q.empty() && q.front()[1] == time) {
      pq.push(q.front()[0]);
      q.pop();
    }
  }

  return time;
}
