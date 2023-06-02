#include <iostream>
#include <string>
/*
•Application should allow recording a minimum of three different days expenses. √
•Daily expenses must be calculated and displayed by accessing the “view daily expenses “option. √
•Manage constructor to initialize the members √
•Weekly expenses should be calculated and displayed √
•Generate daily reports and weekly reports √
•Manage structure array to record multiple days expenses √
•Manage functions to get input and generate reports like daily and weekly expenses √
•Manage relevant menu items to access the features. √
*/
using namespace std;
struct PersonalExpensesManager//This stores all of the expenses and dates.
{
    struct ExpenseDate//The date of an expense ,its value & type.
    {
        struct Value//The value & type of an expense.
        {
            struct expenses
            {
                int TransportCosts, MealCost, EntertainmentCost, HousingCost;
            };
            expenses DailyExpenses;
        };
        struct Days//The day of week a expense was incurred.
        {
            Value Days[7];
        };
        struct Week//Which week of the month a expense was incurred.
        {
            Days Week[4];
        };
        struct Month//The Month of the year a expense was incurred.
        {
            Week Month[12];
        };
        Month Year;
    };

    ExpenseDate PersonalExpenses;
    PersonalExpensesManager()//Constructor of PersonalExpensesManager that sets some initial values.
    {

        User.PersonalExpenses.Year.Month[1].Week[1].Days[1].DailyExpenses.EntertainmentCost = 100;
        User.PersonalExpenses.Year.Month[1].Week[1].Days[1].DailyExpenses.HousingCost = 1200;
        User.PersonalExpenses.Year.Month[1].Week[1].Days[1].DailyExpenses.MealCost = 50;
        User.PersonalExpenses.Year.Month[1].Week[1].Days[1].DailyExpenses.TransportCosts = 12;
    }
} User;
void daysExpenses(int m, int w, int d)//This displays the total expenses of a selected Day.
{
    cout << "\nDaily expenses of Day : " << d << " of week : " << w << " of Month : " << m << "\n$"
     << User.PersonalExpenses.Year.Month[m].Week[w].Days[d].DailyExpenses.EntertainmentCost 
      + User.PersonalExpenses.Year.Month[m].Week[w].Days[d].DailyExpenses.HousingCost
      + User.PersonalExpenses.Year.Month[m].Week[w].Days[d].DailyExpenses.MealCost 
      + User.PersonalExpenses.Year.Month[m].Week[w].Days[d].DailyExpenses.TransportCosts << endl;
}
void weeksExpenses(int m, int w)//This displays the total sum expenses of a selected week.
{
    int Cost = 0;
    cout << "\nDaily expenses of Week" << w << "-" << m << "\n $";
    for (int i = 0; i < 7; i++)
    {
        Cost +=
            User.PersonalExpenses.Year.Month[m].Week[w].Days[i].DailyExpenses.EntertainmentCost +
            User.PersonalExpenses.Year.Month[m].Week[w].Days[i].DailyExpenses.HousingCost +
            User.PersonalExpenses.Year.Month[m].Week[w].Days[i].DailyExpenses.MealCost +
            User.PersonalExpenses.Year.Month[m].Week[w].Days[i].DailyExpenses.TransportCosts;
    }
    cout << Cost << endl;
}
int main()
{
    bool run = true;
    PersonalExpensesManager r1;
    while (run == true)//loops the program.
    {
        int input;
        cout <<"\nSee daily Expenses [1]\n"
         << "See Weekly Expenses [2]\n"
         << "Add daiy expenses[3]\n"
         << "Exit Program[4]\n";

        cin >> input;// Holds the  users input.
        switch (input)// This lets a user set a value of an expense of a type corresponding to 'input'
        {
            case 1://This let a user look at the total expenses of a selected day.
            {
                int m, w, d;
                cout << "\nFor what date\n"
                    << "\nMonth of the year 1-12\n";
                cin >> m;
                cout << "\nWeek of the Month 1-4\n";
                cin >> w;
                cout << "\nDay of the Week 1-7\n";
                cin >> d;
                daysExpenses(m, w, d);//calls the daysExpenses function and passes it the date of the day the user wants the total expenses of.
            }
            break;
            case 2://This let a user look at the total expenses of a selected week.
            {
                int m, w, d;

                cout << "\nFor what date\n"
                    << "\nMonth of the year 1-12\n";
                cin >> m;
                cout << "\nWeek of the Month 1-4\n";
                cin >> w;
                weeksExpenses(m,w);//calls the weeksExpenses function and passes it the date of the week the user wants the total expenses of.
            }
            break;
            case 3://This lets a user add expenses at a user set date.
            {
                bool escape = false;
                int m, w, d, e;
                cout << "\nFor what date\n"
                    << "\nMonth of the year 1-12\n";
                cin >> m;
                cout << "\nWeek of the Month 1-4\n";
                cin >> w;
                cout << "\nDay of the Week 1-7\n";
                cin >> d;

                while (escape == false)//Loops so the user can add more than one expense to one day
                {
                    e = 0;
                    cout << "what Expense\n"
                        << "\nEntertainment[1]"
                        << "\nHousing[2]"
                        << "\nMeal[3]"
                        << "\nTransport[4]"
                        << "\nStop Adding Expenses[5]\n";
                    cin >> e;// Holds the  users input.
                    switch (e)// This lets a user set a value of an expense of a type corresponding to 'e'
                    {
                        case 1:// This lets a user set a value of an expense of Entertainment Cost.
                        {
                            cout << "\nWhat Amount\n";
                            cin >> User.PersonalExpenses.Year.Month[m].Week[w].Days[d].DailyExpenses.EntertainmentCost;
                        }
                        break;
                        case 2:// This lets a user set a value of an expense of Housing Cost.
                        {
                            cout << "\nWhat Amount\n";
                            cin >> User.PersonalExpenses.Year.Month[m].Week[w].Days[d].DailyExpenses.HousingCost;
                        }
                        break;
                        case 3:// This lets a user set a value of an expense of Meal Cost.
                        {
                            cout << "\nWhat Amount\n";
                            cin >> User.PersonalExpenses.Year.Month[m].Week[w].Days[d].DailyExpenses.MealCost;
                        }
                        break;
                        case 4:// This lets a user set a value of an expense of Transport Costs.
                        {
                            cout << "\nWhat Amount\n";
                            cin >> User.PersonalExpenses.Year.Month[m].Week[w].Days[d].DailyExpenses.TransportCosts;
                        }
                        break;
                        case 5://This lets the user stop adding expenses.
                        {
                            escape = true;
                        }
                        break;
                        default://This tells the the user if they try to enter an invalid input. 
                        {
                            cout <<"\n\nInvalid Input\nValid Inputs are 1-5\n\n";
                        }
                        break;
                    }
                }
            }
            break;
            case 4://This ends the programe.
            {
                run = false;
            }
            break;
            default://This tells the the user if they try to enter an invalid input. 
            {
                cout <<"\n\nInvalid Input\nvalid inputs are 1-4\n\n";
            }
            break;
        }
    }
}
