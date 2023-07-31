#pragma once
#include <vector>
#include <string>
#include <map>
using namespace std;

int longest_non_repeating_substring(string &input) {
	map<char, int> map;
	int i, j, max;
	max = 0;
	i = 0;
	
	for (j = 0; j < input.size(); j++) {
		char c = input[j];
		while (map.find(c) != map.end()) {
			map.erase(input[i]);
			i++;
		}
		map[c] = 1;
		max = (map.size() > max) ? map.size() : max;
	}
	
	return max;
}