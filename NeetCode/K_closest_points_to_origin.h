#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
#include "math.h"
#include <queue>
using namespace std;

vector<vector<int>> k_closest(vector<vector<int>>& points, int k) {
  vector<tuple<float, int, int>> triples;
  for(auto p : points) {
    int delta_1 = pow(p[0] - 0, 2);
    int delta_2 = pow(p[1] - 0, 2);

    auto dist = sqrt(delta_1 + delta_2);

    triples.push_back(tuple<float, int, int> {dist, p[0], p[1]});
  }

  auto cmp = [](const tuple<float, int, int>& left, const tuple<float, int, int>& right) {
    return get<0>(left) > get<0>(right);
  };

  priority_queue<tuple<float, int, int>, vector<tuple<float, int, int>>, decltype(cmp)> pq(cmp);

  for(const auto& t : triples) {
    pq.push(t);
  }

  vector<vector<int>> result;
  while(k--) {
    tuple<float, int, int> triple = pq.top();
    vector<int> r = {
      get<1>(triple),
      get<2>(triple)
    };
    pq.pop();
    result.push_back(r);
  }

  return result;
}
