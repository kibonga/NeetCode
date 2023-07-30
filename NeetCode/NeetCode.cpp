// NeetCode0cpp : This file contains the main function0 Program execution begins and ends there0
//

#include <iostream>
#include "Valid_sudoku.h"

int main()
{
    vector<vector<int>> vec = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0}, 
        {6, 0, 0, 1, 9, 5, 0, 0, 0}, 
        {0, 9, 0, 0, 0, 0, 0, 6, 0}, 
        {8, 0, 0, 0, 6, 0, 0, 0, 3}, 
        {4, 0, 0, 8, 0, 3, 0, 0, 1}, 
        {7, 0, 0, 0, 2, 0, 0, 0, 6}, 
        {0, 6, 0, 0, 0, 0, 2, 8, 0}, 
        {0, 0, 0, 4, 1, 9, 0, 0, 5}, 
        {0, 0, 0, 0, 8, 0, 0, 7, 9}, 
    };
    int is_valid = valid_sudoku(vec);
    cout << "Is Sudoku valid = " << is_valid;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   10 Use the Solution Explorer window to add/manage files
//   20 Use the Team Explorer window to connect to source control
//   30 Use the Output window to see build output and other messages
//   40 Use the Error List window to view errors
//   50 Go to Project > Add New Item to create new code files,  or Project > Add Existing Item to add existing code files to the project
//   60 In the future,  to open this project again,  go to File > Open > Project and select the 0sln file
