
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

double find_median(vector<int> &nums1, vector<int> &nums2) {
  int size, low, high, i, j, left_n, left_m, right_n, right_m;
  double median = 0.0;

  int n = nums1.size();
  int m = nums2.size();

  if (m > n) {
    return find_median(nums2, nums1);
  }

  size = n + m;
  low = 0;
  high = m; // size of smaller vector

  while (low <= high) {
    i = low + (high - low) / 2; // index for smaller vector
    j = (size + 1) / 2 - i;     // index for larger vector

    // smaller vector
    left_m = (i > 0) ? nums2[i - 1] : INT32_MIN;
    right_m = (i < m) ? nums2[i] : INT32_MAX;

    // larger vector
    left_n = (j > 0) ? nums1[j - 1] : INT32_MIN;
    right_n = (j < n) ? nums1[j] : INT32_MAX;

    if (left_m <= right_n && left_n <= right_m) {
      if ((size % 2 == 0)) {
        median = (max(left_n, left_m) + min(right_m, right_n)) / 2.0;
        return median;
      } else {
        median = max(left_m, left_n);
        return median;
      }
    } else if (left_m > right_n) {
      high = i - 1;
    } else {
      low = i + 1;
    }
  }

  return median;
}
