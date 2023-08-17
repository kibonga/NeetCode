#pragma once
#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

int reverse_polish_notation(vector<string> strs) {
	stack<int> numbers;
	int opr1, opr2, result, num;
	if (strs.empty()) return 0;
	for (auto s : strs) {
		if ((s == "+") || (s == "-") || (s == "*") || (s == "/")) {
			if (!numbers.empty()) {
				opr2 = numbers.top();
				numbers.pop();
			}
			if (numbers.empty()) continue;
			opr1 = numbers.top();
			numbers.pop();
			if (s == "+") result = opr1 + opr2;
			else if (s == "-") result = opr1 - opr2;
			else if (s == "*") result = opr1 * opr2;
			else if (s == "/") result = opr1 / opr2;
			numbers.push(result);
			continue;
		}	
		num = stoi(s);
		numbers.push(num);
	}
	return numbers.top();
}
