#pragma once
#include <stdio.h>
#include <vector>
#include <stack>
using namespace std;

int largest_rectangle_area(vector<int>& heights) {
    stack<int> stack;
    vector<int> start, end;

    int n = heights.size();
    int item;

    for (int i = 0; i < n; i++) {
        item = heights[i];
        if (stack.empty()) {
            stack.push(i);
            start.push_back(0);
            continue;
        }
        
        while (!stack.empty() && heights[stack.top()] >= item) {
            stack.pop();
        }

        if (stack.empty()) start.push_back(0);
        else start.push_back(stack.top() + 1);
        
        stack.push(i);
    }

    while (!stack.empty()) {
        stack.pop();
    }

    for (int i = n - 1; i >= 0; i--) {
        item = heights[i];
        if (stack.empty()) {
            stack.push(i);
            end.push_back(n - 1);
            continue;
        }

        while (!stack.empty() && heights[stack.top()] >= item) {
            stack.pop();
        }

        if (stack.empty()) end.push_back(n - 1);
        else end.push_back(stack.top() - 1);

        stack.push(i);
    }

    reverse(end.begin(), end.end());
	
    int max_area = 0;
    for (int i = 0; i < n; i++) {
        max_area = max(max_area, heights[i] * (start[i] - end[i] + 1));
    }

    return max_area;
}
