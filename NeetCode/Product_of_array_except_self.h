#pragma once
#include <vector>
using namespace std;

struct node {
	int value = 1;
};

void product_of_array_except_self(vector<int> &nums, vector<int> &answer) {
	int prefix = 1;
	for (int i = 0; i < nums.size(); i++) {
		answer[i] = prefix;
		prefix *= nums[i];
	}
	int postfix = 1;
	for (int i = nums.size() - 1; i >= 0; i--) {
		answer[i] *= postfix;
		postfix *= nums[i];
	}
}