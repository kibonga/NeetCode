#pragma once
#include <string>
#include <unordered_map>
using namespace std;

int valid_anagram(string s1, string s2) {
	int size = s1.length();
	unordered_map<char, int> umap;
	if (size != s2.length()) return 0;
	int m, n;
	for (int i = 0; i < size; i++) {
		m = s1[i], n = s2[i];
		if (m >= 'A' && m <= 'Z') m += 32;
		if (n >= 'A' && n <= 'Z') n += 32;

		umap[m] += 1;
		umap[n] -= 1;
	}
	for (const auto& pair : umap) {
		if (pair.second != 0) return 0;
	}
	return 1;
}