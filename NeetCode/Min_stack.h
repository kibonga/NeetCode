#pragma once
#include <stack>
#include <iostream>
using namespace std;

class MinStack {
public:
	stack<int> min_values;
	stack<int> stack;
	MinStack() {
	}
	void push_min(int val) {
		stack.push(val);
		if (min_values.size() == 0 || min_values.top() > val) min_values.push(val);
	}
	void pop_min() {
		if (stack.size() == 0) {
			cout << "Cannot pop, Stack already empty" << endl;
			return;
		}
		int pop_value = stack.top();
		int min_values_top = min_values.top();
		stack.pop();
		if (pop_value == min_values.top()) min_values.pop();
	}
	int top() {
		if (stack.size() == 0) {
			cout << "Cannot get top, stack already empty" << endl;
			return INT_MIN;
		}
		return stack.top();
	}
	int get_min() {
		if (min_values.size() == 0) {
			cout << "Cannot get min value, stack already empty" << endl;
			return INT_MIN;
		}
		return min_values.top();
	}
};
