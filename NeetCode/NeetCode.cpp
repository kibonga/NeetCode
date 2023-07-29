// NeetCode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Top_k_frequent_elements.h"

int main()
{
    int k = 3;
    vector<int> top_k_elems(k);
    vector<int> vec{1, 1, 1, 2, 2, 4, 7, 7, 7, 7, 6, 6, 5, 5, 5 };
    top_k_freq_elems(vec, k, top_k_elems);

    cout << "Top " << k << " elements = ";
    for (auto k : top_k_elems) {
        cout << k << " ";
    }
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
