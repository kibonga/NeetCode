#include <stdio.h>
#include <stack>
#include <vector>
using namespace std;

void backtrack(int open, int close, stack<char>& stack, vector<string>& result) {
    if (!open && !close) {
        string str;
        while (!stack.empty()) {
            str += stack.top();
            stack.pop();
        }
        reverse(str.begin(), str.end());
        for (auto s : str) {
            stack.push(s);
        }
        result.push_back(str);
        return;
    }
    if (open && open <= close) {
        stack.push('(');
        backtrack((open - 1), close, stack, result);
        stack.pop();
    }
    if (open < close) {
        stack.push(')');
        backtrack(open, (close - 1), stack, result);
        stack.pop();
    }
}

void generate_parentheses(int n, vector<string>& result) {
    stack<char> stack;
    backtrack(n, n, stack, result);
}

