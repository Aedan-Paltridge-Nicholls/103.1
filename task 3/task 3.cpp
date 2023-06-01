// task 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <ctime>
#include <iostream>
const int XAxis = 3;//This the X of the matrixs.
const int YAxis = 3;//This the Y of the matrixs.
int M1[XAxis][YAxis];//This creates matrix 1.
int M2[XAxis][YAxis];//This creates matrix 2.
int M3[XAxis][YAxis];//This creates matrix 3.
int randoms()//This creates a random number 
{
	int random = (rand() % 10) + 1;//random number generator
	return random;
}
void displaym1and2()
{
	
	for (int i = 0; i < XAxis; i++)//This randomizes the values of matrix 1 & 2.
	{
		for (int j = 0; j < YAxis; j++)
		{
			
			M1[i][j] = randoms();
			M2[i][j] = randoms();
		}
	}
	std::cout << "\nMatrix 1";
	for (int i = 0; i < XAxis; i++)//This displays matrix 1.
	{
		std::cout << "\n{";
		for (int j = 0; j < YAxis; j++) { std::cout << M1[i][j]<<","; }
		std::cout << "}";
	}
	std::cout << "\nMatrix 2";
	for (int i = 0; i < XAxis; i++)//This displays matrix 2.
	{
		std::cout << "\n{";
		for (int j = 0; j < YAxis; j++) { std::cout << M2[i][j] << ","; }
		std::cout << "}";
	}

}
void matrix3()
{
	std::cout << "\nMatrix 3";
	for (int i = 0; i < XAxis; i++)//This adds matrix 1 & 2 then multiplies the sum by three then the value of displays matrix 3.
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
	std::srand(time(nullptr));//This seeds the random number generator.
	displaym1and2();//This calls the function displaym1and2.
	matrix3();//This calls the function matrix3. 
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
