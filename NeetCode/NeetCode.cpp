// NeetCode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Implement_trie.h"

int main()
{
  TrieNode* trie = new TrieNode();
  string word = "apple";
  insert(trie, word);
  cout << "Search 'Apple' = " << search(trie, word) << endl;
  string word2 = "app";
  cout << "Search 'App' = " << search(trie, word2) << endl;
  cout << "Starts with 'App' = " << starts_with(trie, word2) << endl;
  insert(trie, word2);
  cout << "Search 'App' = " << search(trie, word2) << endl;
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
