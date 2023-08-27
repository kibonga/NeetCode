#include <iostream>
#include <map>
#include <stdio.h>
#include <string>
#include <utility>
#include <vector>
using namespace std;

class TimeMap {
public:
  std::map<string, vector<pair<int, string>>> map;
  TimeMap() {}
  void set(string key, string value, int timestamp);
  pair<int, string> get(string kye, int timestamp);
};

void TimeMap::set(string key, string value, int timestamp) {
  map[key].push_back(make_pair(timestamp, value));
}

pair<int, string> TimeMap::get(string key, int timestamp) {
  if (map.find(key) == map.end()) {
    cout << "Key not found at all" << endl;
    return make_pair(-1, "");
  }

  vector<pair<int, string>> vec = map[key];
  pair<int, string> pair;
  string res = vec[0].second;
  int low, high, mid;
  low = 0;
  high = map[key].size() - 1;

  while (low <= high) {
    mid = low + (high - low) / 2;
    pair = vec[mid];
    if (pair.first < timestamp) {
      low = mid + 1;
    } else if (pair.first > timestamp) {
      high = mid - 1;
    } else {
      return pair;
    }
  }

  if (high >= 0) {
    return map[key][high];
  }

  return make_pair(-2, "");
}
