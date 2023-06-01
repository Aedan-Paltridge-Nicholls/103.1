// Task 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
const int listsize = 10;//This is the length of the list. 

int sum(int *pointer, int listsize)//This sums up all non-negitive numbers in the list.
{
	int runsum = 0;//This stores a running total of the  non-negitive numbers in the list.
	for (int i = 0; i < listsize; i++)
	{
		if (*pointer >= 0)//This checks if the value at the pointer is non-negitive numbers.
		{
			runsum = runsum + *pointer;//This adds non-negitive numbers to the running total.
		}
		pointer++;//This moves the pointer to the next entry on the list. 
	}
	return runsum;
}
int main()
{
	int list[listsize];//This creates the list.
	int *pointer;//This creates the pointer
	pointer = list;//This sets the poninter address of the list 
	
	std::cout <<"set values to list number "<<std::endl;
	for (int i = 0; i < listsize; i++)//This make users add the values to the list.
	{
		std::cout <<"\n" << (i + 1) << " :";
		std::cin >> list[i];

	}
	//This displays the sum of all non-negitive numbers in the list by calling the sum function.
	std::cout << "\n Sum of non-negative values of list ="  << sum(pointer, listsize)<<std::endl;


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
