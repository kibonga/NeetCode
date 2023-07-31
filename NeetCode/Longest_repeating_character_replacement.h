#pragma once
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int longest_repeating_char(string str) {
	int i, j, max, len;
	max = 0;
	i = 0;

	for (j = 0; j < str.size(); j++) {
		char c = str[i];
		while (c == str[j]) {
			j++;
		}
		len = j - i;
		max = (len > max) ? len : max;
		i = j;
	}

	return max;
}

int longest_char_replacement(string str, int k) {
	map<char, int> map;
	int i, j, max, len;
	max = 0;
	i = 0;

	for (j = 0; j < str.size(); j++) {
		char c = str[j];
		map[c] += 1;

		if (str[i] == c) {
			max++;
			continue;
		}
		int val = max_element(map.begin(), map.end(), [](const auto& x, const auto& y) { return x.second < y.second; })->second;

		len = j - i + 1;
		int isValid = len - val <= k;
		if (!isValid) {
			map[str[i]] -= 1;
			i++;
			continue;
		}

		max = (len > max) ? len : max;
		
	}
	return max;
}