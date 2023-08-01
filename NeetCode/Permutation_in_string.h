#pragma once
#include <string>
#include <map>
using namespace std;

int check_inclusion(string s1, string s2) {
	map<char, int> temp_map;
	map<char, int> map;
	int i, j, k, len;
	len = 0;
	char c;

	for (i = 0; i < s1.size(); i++) {
		c = s1[i];
		map[c] += 1;
	}

	for (j = 0; j < s2.size(); j++) {
		c = s2[j];
		if (map.find(c) == map.end()) continue;
		k = i;
		i = j++;
		while (map.find(s2[j]) != map.end()) {
			c = s2[j];
			int val = map[c] -= 1;
			if (val <= 0) {
				map.erase(c);
			}
			temp_map[c] += 1;
			j++;
		}
		j--;
		len = (j - i + 1);
		for (auto& m : temp_map) {
			map[m.first] = m.second;
		}
		temp_map.clear();
		if (map.size() == len) {
			return 1;
		}
		j = i;
		i = k;
	}

	return 0;
}
