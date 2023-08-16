// NeetCode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Min_stack.h"

int main()
{
	MinStack min_stack = MinStack();
	min_stack.push_min(-2);
	min_stack.push_min(0);
	min_stack.push_min(-3);
	min_stack.push_min(4);
	min_stack.push_min(1);

	min_stack.pop_min();
	min_stack.pop_min();
	min_stack.pop_min();
	min_stack.pop_min();
	cout << "Min stack value = " << min_stack.get_min();
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
