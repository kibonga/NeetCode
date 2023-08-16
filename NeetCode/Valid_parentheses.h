#pragma once
#include <string>
#include <stack>
using namespace std;

int valid_parentheses(string string) {
	stack<char> stack;
	char p;

	for (auto s : string) {
		if ((s == '(') || (s == '[') || (s == '{')) {
			stack.push(s);
			continue;
		}
		if (stack.empty()) return 0;
		p = stack.top();
		if ((s == '(' && p != ')') ||
			(s == '{' && p != '}') ||
			(s == '[' && p != ']')) return 0;
		stack.pop();
	}
	return stack.empty();
}
