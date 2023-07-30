#pragma once
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> three_sum(vector<int> &vec) {
	sort(vec.begin(), vec.end());
	vector<vector<int>> result;
	int i, j, k, size, left, right, target, sum;
	size = vec.size();
	i = 0;
	j = i + 1;
	k = size - 1;
	while (i < size - 1) {

		if (j == k) {
			i++;
			j = i + 1;
			k = size - 1;
			continue;
		}

		target = vec[i];
		left = vec[j];
		right = vec[k];
		sum = left + right + target;

		if (sum < 0) {
			j++;
			continue;
		}

		if (sum > 0) {
			k--;
			continue;
		}

		vector<int> v = { vec[i], vec[j], vec[k] };
		result.push_back(v);
		i++;
		j = i + 1;
		k = size - 1;
	}

	return result;
}
