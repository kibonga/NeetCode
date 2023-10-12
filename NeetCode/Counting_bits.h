#include <iostream>
#include <vector>
using namespace std;

void count_bits(int n, vector<int>& result) { 

  for(int i=1; i<=n; i++) {
    result[i] = result[i >> 1] + (i & 1);
  }
    
}
