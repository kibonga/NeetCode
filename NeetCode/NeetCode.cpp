// NeetCode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Contains_duplicates.h"

int main()
{
    clock_t start = clock();
    for (int i = 0; i < 1000000; i++) {
        vector<int> vec{5, 6, 4, 3, 2, 1, 5};
        contains_duplicates(vec);
    }
    cout << "Excecution time = " << (double)(double(clock() - start) / CLOCKS_PER_SEC) << "s" << endl;
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
