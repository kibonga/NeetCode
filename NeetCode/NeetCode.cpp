// NeetCode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Design_add_and_search_words_data_structure.h"

int main()
{
  TrieNode* trie = new TrieNode(); 
  string word1 = "bad";
  string word2 = "dad";
  string word3 = "mad";
  add(trie, word1);
  add(trie, word2);
  add(trie, word3);

  string search_word1 = "pad";
  string search_word2 = "bad";
  string search_word3 = ".ad";
  string search_word4 = "b..";
  string search_word5 = "b.d";

  int search1 = search(trie, search_word1);
  int search2 = search(trie, search_word2);
  int search3 = search(trie, search_word2);
  int search4 = search(trie, search_word3);
  int search5 = search(trie, search_word5);

  cout << "Search 'pad' = " << search1 << endl;
  cout << "Search 'bad' = " << search2 << endl;
  cout << "Search '.ad' = " << search3 << endl;
  cout << "Search 'b..' = " << search4 << endl;
  cout << "Search 'b.d' = " << search5 << endl;
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
