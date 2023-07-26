#pragma once
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

void group_anagrams(vector<string> &vec, vector<vector<string>> &res) {
	map<string, int> map;
	for (int i = 0; i < vec.size(); i++) {
		string temp(vec.size(), ' ');
		transform(vec[i].begin(), vec[i].end(), temp.begin(), ::tolower);
		sort(temp.begin(), temp.end());

		if (map.find(temp) == map.end()) {
			map[temp] = i;
			res[i].push_back(vec[i]);
			continue;
		}
		else {
			res[map[temp]].push_back(vec[i]);
		}
	}
}
