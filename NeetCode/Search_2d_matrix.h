#pragma once
#include <iostream>
#include <vector>
using namespace std;

int search_matrix(vector<vector<int>>& matrix, int target) {
    int n, m, low_row, high_row, mid_row, last, first, elem, mid_col, low_col, high_col;
    n = matrix[0].size();
    m = matrix.size();
    high_row = m - 1;
    low_row = 0;
    high_col = n - 1;
    low_col = 0;

    while (high_row >= low_row) {
        mid_row = (high_row - low_row) / 2 + low_row;
        first = matrix[mid_row][0];
        if (target == first) {
            cout << "Element found happy path" << endl;
            return 1;
        }
        last = matrix[mid_row][n - 1];
        if (target < first) {
            // Change row
            high_row = mid_row - 1;
        }
        else if (target > last) {
           // Change row 
            low_row = mid_row + 1;
        }
        else if (target < last) {
           // Search row
            high_col = n - 1;
            low_col = 0;
            while (high_col > low_col) {
                mid_col = (high_col - low_col) / 2 + low_col;
                elem = matrix[mid_row][mid_col];
                if (elem == target) {
                    cout << "Element found" << endl;
                    return 1;
                }
                else if (target > elem) {
                    low_col = mid_col + 1;
                } 
                else if (target < elem) {
                    high_col = mid_col - 1;
                }
            }
            cout << "Element not found" << endl;
            return -1;
        }
    }
    cout << "Element not found" << endl;
    return -1;
}
