#pragma once
#include <stdio.h>
#include <vector>
using namespace std;

vector<int> max_sliding_window(vector<int>& nums, int k) {
    vector<int> result;
    int i, j, t, max, right, temp;
    i = 0, j = k, max = INT_MIN;

    for (t = 0; t < k; t++) {
        temp = nums[t];
        if (temp > max) {
            max = temp;
            i = t;
        }
    }

    result.push_back(nums[i]);

    for (t = 1; t < (nums.size() - k + 1); t++) {

        if (t > i) {
            max = INT_MIN;
            for (int m = t; m < (t + k); m++) {
                temp = nums[m];
                if (temp > max) {
                    i = m;
                    max = temp;
                }
            }
        }
        else {
            max = nums[i];
        }

        right = nums[j];
        if (right > max) {
            max = right;
            i = j;
        }

        j++;
        result.push_back(max);
    }
    
    return result;
}
