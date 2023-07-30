#pragma once
#include <vector>
#include <tuple>
using namespace std;

tuple<int, int> two_sum(vector<int> &vec, int target) {

	int size = vec.size();
	int i = 1;
	int j = size - 1;

	int left, right, sum;
	while (i < j) {
		left = vec[i];
		right = vec[j];
		sum = left + right;

		if (sum > target) {
			j--;
			continue;
		}

		if (sum < target) {
			i++;
			continue;
		}

		return make_tuple(i, j);
	}

	return make_tuple(0, 0);
}