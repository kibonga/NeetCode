#pragma once
#include <string>
using namespace std;

int valid_palindrome(string str) {
	int size = str.size();
	int i = 0;
	int j = size - 1;
	char left, right;
	while (i < j) {
		left = tolower(str.at(i));
		right = tolower(str.at(j));

		if (!isalnum(left)) {
			i++;
			continue;
		}
		if (!isalnum(right)) {
			j--;
			continue;
		}

		if (left != right) return 0;
		i++;
		j--;
	}
	return 1;
}