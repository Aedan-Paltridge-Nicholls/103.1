// Task 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
enum Position
{
	// these are the Positions that can be set for each of the two Soccer players
	goalkeeper, midfielder, striker, winger, defender
}PPos;
struct PlayerRecord
{
	// these are the info that can be set for each of the two Soccer players
	int	PlayerNumber;// the Soccer players number 
	float Playerspeed; // the Soccer players top speed (in MPH)
	Position PlayerPosition; // the Position of the Soccer Player  
};
PlayerRecord Players[2];
int main()
{
	bool exit =  false;
	int imput;
	while (!exit)
	{
		std::cout << "\nEnter \n[1]Player Number\n[2]player's top speed\n[3]Player Position\n[4]display players\n";
		std::cin >> imput;
		switch (imput)
		{
			case 1:
			{
				
				for (int i = 0; i < 2; i++)
				{
					std::cout << "Enter Player Number\n" << "For player : " << (i+1) << "\n";
					std::cin >> Players[i].PlayerNumber;
				}
			}break;
			case 2:
			{
				for (int i = 0; i < 2; i++)
				{
					std::cout << "player's top speed in MPH\n" << "For player : " << (i + 1) << "\n";
					std::cin >> Players[i].Playerspeed;
				}
			}break;
			case 3:
			{
				char PlayPos;
				for (int i = 0; i < 2; i++)
				{
					std::cout << "Enter Player Position\n"
						<<"(G)oalkeeper, (M)idfielder, (S)triker, (W)inger, (D)efender\n"
						<<"For player : " << (i + 1) << "\n";
					std::cin >> PlayPos;
					PlayPos = toupper(PlayPos);
					switch (PlayPos)
					{
						case 'G':
						{
							Players[i].PlayerPosition = goalkeeper;
						}break;
						case 'M':
						{
							Players[i].PlayerPosition = midfielder;
						}break;
						case 'S':
						{
							Players[i].PlayerPosition = striker;
						}break;
						case 'W':
						{
							Players[i].PlayerPosition = winger;
						}break;
						case 'D':
						{
							Players[i].PlayerPosition = defender;
						}break;
					
						default:
							break;
					}
				}break;
				case 4:
				{
					for (int i = 0; i < 2; i++)
					{
						std::cout << "Player : " << (i + 1) << std::endl
						<< "Player Number :" << Players[i].PlayerNumber << std::endl
						<< "Player top Speed in MPH: " << Players[i].Playerspeed << std::endl
						<< "Player Player Position: ";
						switch (Players[i].PlayerPosition)
						{
							case goalkeeper:
							{
								std::cout << "goalkeeper" << std::endl;
							}break;
							case midfielder:
							{
								std::cout << "midfielder" << std::endl;
							}break;
							case striker:
							{
								std::cout << "striker" << std::endl;
							}break;
							case winger:
							{
								std::cout << "winger" << std::endl;
							}break;
							case defender:
							{
								std::cout << "defender" << std::endl;
							}break;

							

						}

					}
				}break;

			}break;
			default:
			break;
		}

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
