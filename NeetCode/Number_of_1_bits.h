#include <cstdint>
#include <iostream>
using namespace std;

int hamming_weight(uint32_t n) {
  int result = 0;

  while(n > 0) {
    result += n % 2;
    n = n >> 1;
  }

  return result;
}
