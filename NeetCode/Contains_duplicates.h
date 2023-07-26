#pragma once
#include <vector>
#include <unordered_map>
using namespace std;

int contains_duplicates(vector<int>& vec) {
	unordered_map<int, int> umap;
	for (int v : vec) {
		if (umap[v] == 1) return 1;
		umap[v] = 1;
	}
	return 0;
}