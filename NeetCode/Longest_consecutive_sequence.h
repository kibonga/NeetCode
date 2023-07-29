#pragma once
#include <vector>
#include <map>
using namespace std;

int longest_consecutive_sequence(vector<int> &vec) {
	map<int, int> result;
	map<int, int> map;

	for (auto& v : vec) {
		map[v] = v;
	}

	cout << "Map result" << endl;
	int longest = 1;
	for (auto& m : map) {
		int next = m.first + 1;
		if (map.find(next) != map.end()) {
			cout << "Key = " << m.first << " and value = " << m.second << " with next key = " << map.at(next) << endl;
			longest++;
		}
		else {
			result[longest] = longest;
			longest = 1;
		}
	}

	return prev(result.end())->second;
}