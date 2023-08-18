#pragma once
#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

void daily_temperatures(vector<int>& temperatures, vector<int>& result) {
	stack<pair<int, int>> stack;
	int i = 0, j, v;
	pair<int, int> top;
	for (auto t : temperatures) {
		if (stack.empty()) {
			stack.push(make_pair(t, i));
			i++;
			continue;
		}
		while (!stack.empty()) {
			top = stack.top();
			v = top.first;
			j = top.second;
			if (t > v) {
				stack.pop();
				result[j] = i - j;
			}
			else {
				stack.push(make_pair(t, i));
				i++;
				break;
			}
		}
		if (t < v) continue;
		stack.push(make_pair(t, i));
		i++;
	}
}
