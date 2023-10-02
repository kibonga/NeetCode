// NeetCode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "Kth_largest_element_in_a_stream.h"

int main()
{
  int k = 3;
  vector<int> vec = vector<int> {4, 5, 8, 2};
  KthLargest* kth = new KthLargest(k, vec);

  add(kth, 3);
  add(kth, 5);
  add(kth, 10);
  add(kth, 9);
  int result = add(kth, 4);

  cout << "Result = " << result << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
