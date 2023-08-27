// NeetCode.cpp : This file contains the 'main' function. Program execution
// begins and ends there.
//

#include "Time_based_key_value_store.h"
#include <iostream>

int main() {
  TimeMap *map = new TimeMap();
  string key = "foo";
  string val = "bar";
  int timestamp = 1;
  map->set(key, val, timestamp);
  map->set("foo", "bar2", 4);
  pair<int, string> res = map->get(key, 5);
  cout << "Result for key " << key << " is value = " << res.second
       << " with timestamp = " << res.first << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add
//   Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project
//   and select the .sln file
