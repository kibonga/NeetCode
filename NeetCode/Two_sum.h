#pragma once
#include <map>
using namespace std;

int* two_sum(int A[], int n, int target, int result[]) {
	map<int, int> map;

	for (int i = 0; i < n; i++) {
		if (map.find(A[i]) != map.end()) {
			result[0] = A[i];
			result[1] = target - A[i];
			return result;
		}
		map[target - A[i]] = 1;
	}
}