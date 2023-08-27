#include <cmath>
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int min_eating_speed(vector<int> &piles, int h) {
  int min_eating_rate, low, high, n, total_hours, hours_per_pile, k;
  n = piles.size();

  low = 0;
  high = -1;
  for (int p : piles) {
    high = max(high, p);
  }
  k = high;

  while (low <= high) {
    min_eating_rate = low + (high - low) / 2;
    total_hours = 0;
    for (int i = 0; i < n; i++) {
      hours_per_pile = ceil((double)piles[i] / min_eating_rate);
      total_hours += hours_per_pile;
    }

    if (total_hours > h) {
      low = min_eating_rate + 1;
    } else {
      k = min(k, min_eating_rate);
      high = min_eating_rate - 1;
    }
  }

  return k;
}
