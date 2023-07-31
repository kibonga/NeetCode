#pragma once
#include <vector>
using namespace std;

int best_stonks(vector<int> &stonks) {
	int profit, min, s;
	profit = 0;
	min = INT_MAX;

	for (int i = 0; i < stonks.size(); i++) {
		s = stonks[i];
		if (s < min) {
			min = s;
			continue;
		}
		profit = (s - min) > profit ? (s - min) : profit;
	}

	return profit;
}