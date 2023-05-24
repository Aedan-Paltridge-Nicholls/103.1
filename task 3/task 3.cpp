// task 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <ctime>
#include <iostream>
const int XAxis = 3;
const int YAxis = 3;
int M1[XAxis][YAxis];
int M2[XAxis][YAxis];
int M3[XAxis][YAxis];
int randoms()
{
	int random = (rand() % 10) + 1;
	return random;
}
void displaym1and2()
{
	
	for (int i = 0; i < XAxis; i++)
	{
		for (int j = 0; j < YAxis; j++)
		{
			
			M1[i][j] = randoms();
			M2[i][j] = randoms();
		}
	}
	std::cout << "\nMatrix 1";
	for (int i = 0; i < XAxis; i++)
	{
		std::cout << "\n{";
		for (int j = 0; j < YAxis; j++) { std::cout << M1[i][j]<<","; }
		std::cout << "}";
	}
	std::cout << "\nMatrix 2";
	for (int i = 0; i < XAxis; i++)
	{
		std::cout << "\n{";
		for (int j = 0; j < YAxis; j++) { std::cout << M2[i][j] << ","; }
		std::cout << "}";
	}

}
void matrix3()
{
	std::cout << "\nMatrix 3";
	for (int i = 0; i < XAxis; i++)
	{
		std::cout << "\n{";
		for (int j = 0; j < YAxis; j++)
		{
			M3[i][j] = (M1[i][j] + M2[i][j])*3;
			std::cout << M3[i][j] << ",";
		}
		std::cout << "}";
	}


}
int main()
{
	std::srand(time(nullptr));
	
	displaym1and2();
	matrix3();
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
