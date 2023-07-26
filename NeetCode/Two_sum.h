#pragma once
#include <unordered_map>
#include <map>
using namespace std;

int* two_sum(int A[], int n, int target, int result[]) {
	map<int, int> umap;

	for (int i = 0; i < n; i++) {
		if (umap.find(A[i]) != umap.end()) {
			result[0] = A[i];
			result[1] = target - A[i];
			return result;
		}
		umap[target - A[i]] = 1;
	}
}