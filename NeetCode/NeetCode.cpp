// NeetCode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Two_sum_II_input_array_is_sorted.h"

int main()
{
    int target = 17;
    vector<int> vec{0};
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    vec.push_back(8);
    vec.push_back(9);
    vec.push_back(11);
    vec.push_back(22);
    vec.push_back(35);


    tuple<int, int> result = two_sum(vec, target);
    cout << "Indices " << endl << "First = " << get<0>(result) << endl << "Second = " << get<1>(result);

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
