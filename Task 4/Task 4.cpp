// Task 4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <string>
#include <iostream>
int guesses = 3;
/*
Use more than one function call. Ideally (5 functions) 
one to draw a line, ✔
one to draw the hangman,✔
one to draw a Walkman, 
one to invert the hangman, ✔
and another one to play.✔
At least one function without parameter(s).✔
At least one function with parameter(s).✔
At least one function without any return value.✔
At least one function with a return value.✔
Assign a function return value to a variable.✔
*/
std::string Theword = "R-p-s-t-r-";//This sets the words to begining state.
const int fixer = 10;//length of Word array.
char Word[10];//Word arry.
 bool e=false,i=false,o=false,y=false;//These are the letter bools so the sate of letters can be stored.
std::string play(char Word[fixer], std::string Theword)//This is where the code for playing the game is.
{
   
    char guess = ' ';
    std::cin >> guess;
    switch (guess) //Checks if a guess is a vaild guess if so it set the corresponding letter to true so it can be add to the word array to be displayed; 
    {
        case 'e':
        {  
         e=true;
        }
        break;
        case 'i':
        {  
         i=true;  
        }
        break;
        case 'o':
        {  
            o=true;
        }
        break;
        case 'y':
        {  
         y=true;
        }
        break;
        default:
        {
            guesses--;//removes one guesses from the user if The guess is not a vaild letter.
        }
         break;
    }
    Word[0] = 'R';
    if (e=true){Word[1] = 'e';}else{Word[1] = '-';}//Checks if e has been guessed  and adds it to the word array if so, if not adding a placeholder.
    Word[2] = 'p';
    if (o=true){Word[3] = 'o';}else{Word[3] = '-';}//Checks if o has been guessed and adds it to the word array if so, if not adding a placeholder.
    Word[4] = 's';
    if (i=true){Word[5] = 'i';}else{Word[5] = '-';}//Checks if i has been guessed and adds it to the word array if so, if not adding a placeholder.
    Word[6] = 't';
    if (o=true){Word[7] = 'o';}else{Word[7] = '-';}//Checks if o has been guessed and adds it to the word array if so, if not adding a placeholder.
    Word[8] = 'r';
    if (o=true){ Word[9] = 'y';}else{Word[9] = '-';}//Checks if y has been guessed and adds it to the word array if so, if not adding a placeholder.
    return  Theword;
}


void DrawHangman()//This displays the normal hangman 
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
void invertHangman()//This displays the  hangman inverted signaling a loss to the user. 
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
void walkman()//This displays the  walkman signaling a Victory to the user.
{
    std::cout
        << "      O\n"
        << "      /|\\ \n"
        << "      / \\ \n"
        << "\n you Win ";
    exit(0);

}
void line(int guesses)//This displays the line under the hangman and the number of guesses left and the current state of the word.
{

    // std::string Theword = "R-p-s-t-r-";// Repository is the word to be guessed
    std::cout << "-----------------\n"
        << "Guess the mising letters  "
        << Theword//This displays the current state of the word.
        << "\nGuesses remaining : " << guesses << std::endl << " ";
    if (Theword == "Repository")//This checks if the user has guessed the word and if they have displays the walkman.
    {
        walkman();//This calls the walkman function.
    }
    Theword = "";
    Theword = play((&Word)[fixer], Theword);//This calls the play function and passes it the word array and it's length, and the "theword" string that it will return.

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
    //Those ↑ set the begining  word sate.
    while (guesses !=0)//This runs the game till the user runs out of guesses
    {
        DrawHangman();//This calls the DrawHangman function.
        line(guesses);//This calls the line function and passes it the guesses count.
    }
    invertHangman();//This calls the invertHangman function because the user has lost.
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
