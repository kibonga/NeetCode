#include <iostream>
using namespace std;

int get_sum(int a, int b) {

  while(b != 0) {
    int c = a & b;
    a = a ^ b;
    b = (unsigned)c << 1;
  }

  return a;
}
