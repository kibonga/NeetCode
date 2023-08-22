#pragma once
#include <stdio.h>
#include <vector>
using namespace std;

int trap(vector<int>& heights) {
    int total, i, j, k, max, temp, left, right, dist;
    total = 0, i = 0, j = 0, max = INT_MIN;

    for (i = 0; i < heights.size(); i++) {
        temp = heights[i];
        if (temp > max) {
            max = temp;
            k = i;
        }
    }

    j = 1;
    for (i = 0; j <= k; j++, i++) {
        left = heights[i];
        right = heights[j];

        if (right >= left) {
            continue;
        }
        
        while (left >= right) {
            j++;
            right = heights[j];
        }
        j;
        dist = j - i - 1;
        total += dist * left;
        i++;
        while (i < j) {
            temp = heights[i];
            total -= temp;
            i++;
        }
        i--;
    }

    i = heights.size() - 1;
    j = i - 1;

    for (; j >= k; j--, i--) {
        right = heights[i];
        left = heights[j];

        if (left >= right) {
            continue;
        }

        while (right > left) {
            j--;
            left = heights[j];
        }
        dist = i - j - 1;
        total += dist * right;
        i--;
        while (i > j) {
            temp = heights[i];
            total -= temp;
            i--;
        }
        i++;
    }
    return total;
}
