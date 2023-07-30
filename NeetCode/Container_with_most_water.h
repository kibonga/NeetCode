#pragma once
#include <vector>
using namespace std;

int container_with_most_water(vector<int> &vec) {
	int max = 0, tempArea = 0;
	int i, j, size, left, right, smaller;
	size = vec.size();
	i = 0;
	j = size - 1;

	while (j > i) {
		left = vec[i];
		right = vec[j];

		smaller = (left <= right) ? left : right;
		tempArea = (j - i) * smaller;
		max = (tempArea > max) ? tempArea : max;

		if (left <= right) i++;
		if (right < left) j--;
	}

	return max;
}