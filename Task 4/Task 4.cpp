// Task 4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <string>
#include <iostream>
int guesses = 3;
/*
Use more than one function call. Ideally (5 functions) 
one to draw a line, X
one to draw the hangman,X
one to draw a Walkman, 
one to invert the hangman, X
and another one to play.X
At least one function without parameter(s).X
At least one function with parameter(s).X
At least one function without any return value.X
At least one function with a return value.X
Assign a function return value to a variable.X
*/
std::string Theword = "R-p-s-t-r-";
const int fixer = 10;
char Word[10];
std::string play(char Word[fixer], std::string Theword)
{
    char guess = ' ';
    std::cin >> guess;
    switch (guess)
    {
        case 'e':
        {
            Word[1] = 'e';//e
        }break;
        case 'i':
        {
            Word[5] = 'i';//i
        }break;
        case 'o':
        {
            Word[3] = 'o';//o
            Word[7] = 'o';//o
        }break;
        case 'y':
        {
            Word[9] = 'y';//y
        }break;

        default:
        {
            guesses--;
        }
            break;
    }
    Word[0] = 'R';
    Word[2] = 'p'; 
    Word[4] = 's';
    Word[6] = 't';
    Word[8] = 'r';
    for (int i = 0; i < 10; i++)
    {
        Theword += Word[i];
    }
    return  Theword;
}


void DrawHangman()
{
    std::cout
        << "__________\n"
        << "|       |\n"
        << "|       O\n"
        << "|      /|\\ \n"
        << "|      / \\ \n"
        << "|\n"
        << "|\n";

}
void invertHangman()
{
    std::cout
        << "__________\n"
        << "|       |\n"
        << "|     \\ / \n"
        << "|      /|\\ \n"
        << "|       O\n"
        << "|\n"
        << "|\n"
        <<"---------------"
        <<"You lose";
    exit(0);

}
void walkman()
{
    std::cout
        << "      O\n"
        << "      /|\\ \n"
        << "      / \\ \n"
        << "\n you Win ";
    exit(0);

}
void line(int guesses)
{


    // std::string Theword = "R-p-s-t-r-";// Repository
    std::cout << "-----------------\n"
        << "Guess the mising letters  "
        << Theword
        << "\nGuesses remaining : " << guesses << std::endl << " ";
    if (Theword == "Repository")
    {
        walkman();
    }
    Theword = "";
    Theword = play((&Word)[fixer], Theword);

}
int main()
{
    Word[0] = 'R';
    Word[1] = '-';//e
    Word[2] = 'p';
    Word[3] = '-';//o
    Word[4] = 's';
    Word[5] = '-';//i
    Word[6] = 't';
    Word[7] = '-';//o
    Word[8] = 'r';
    Word[9] = '-';//y
    while (guesses !=0)
    {
        DrawHangman();
        line(guesses);
    }
    invertHangman();
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
