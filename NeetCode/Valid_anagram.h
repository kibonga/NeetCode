#pragma once
#include <string>
using namespace std;

int valid_anagram(string s1, string s2) {
	int size = s1.length();
	if (size != s2.length()) return 0;
	int A[255] = { 0 };
	int m, n;
	for (int i = 0; i < size; i++) {
		m = s1[i];
		n = s2[i];
		if (m >= 'A' && m <= 'Z') m += 32;
		if (n >= 'A' && n <= 'Z') n += 32;

		A[m] += 1;
		A[n] -= 1;
	}

	for (int i = 0; i < size; i++) {
		if (A[i] != 0) return 0;
	}

	return 1;

}