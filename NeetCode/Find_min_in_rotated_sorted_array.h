#include <cstdint>
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int find_min(vector<int> &nums) {
  int n, left, right, i, j, min, mid, t, temp;
  n = nums.size();
  i = 0;
  j = n - 1;
  left = nums[i];
  right = nums[j];
  min = left;

  while (i < j - 1) {
    left = nums[i];
    right = nums[j];

    t = (j - i) / 2 + i;
    temp = nums[t];
    min = temp < min ? temp : min;

    if (left > right) {
      if ((temp > right) || (temp < left)) {
        i = t;
      } else if ((temp < right) || (temp > left)) {
        j = t;
      }
    } else if (right > left) {
      if ((temp < left) || (temp < right)) {
        i = t;
      } else if ((temp > left) || (temp > right)) {
        j = t;
      }
    }
  }

  return min;
}
