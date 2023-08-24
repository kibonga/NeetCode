#pragma once
#include <iostream>
#include <vector>
using namespace std;

int binary_search(vector<int>& numbers, int target) {
    int mid, h, l, num;
    l = 0, h = numbers.size() - 1;
    while (h > l) {
        mid = (h - l) / 2 + l;
        num = numbers[mid];
        if (target == num) {
            cout << "Element found at index = " << mid << endl;
            return mid;
        }
        else if (target > num) {
            l = mid + 1;
        }
        else {
            h = mid - 1;
        }
    }
    cout << "Element not found" << endl;
    return -1;
}
