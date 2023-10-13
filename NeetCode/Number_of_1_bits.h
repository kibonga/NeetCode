#include <cstdint>
#include <iostream>
using namespace std; 

int hamming_weight(uint32_t n) {
  int bit = 0;
  int result = 0;

  while(n) {
    bit = n & 1;
    if(bit == 1) {
      result++;
    }
    n = n >> 1;
  } 
    
  return result;
}
