#pragma once
#include <map>
#include <unordered_map>
using namespace std;

void top_k_freq_elems(vector<int> &vec, int k, vector<int> &result) {
	map<int, int> map;
	vector<vector<int>> freq(vec.size(), vector<int>());
	int n = vec.size();

	for (const auto v : vec) {
		map[v] += 1;
	}

	for (const auto m : map) {
		freq[m.first].push_back(m.second);
	}

	int res = result.size();
	for (int i = n - 1; i >= 0; i--) {
		if (result.size() >= k) return;
		int s = freq[i].size();
		for (const auto f : freq[i]) {
			result.push_back(f);
		}
	}
}
