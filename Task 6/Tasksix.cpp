#include <iostream>
#include <string>
/*
•Daily expenses must be calculated and displayed by accessing the “view daily expenses “option.
•Application should allow recording a minimum of three different days expenses.
•Weekly expenses should be calculated and displayed
•Manage constructor to initialize the members
•Manage structure array to record multiple days expenses
•Generate daily reports and weekly reports
•Manage functions to get input and generate reports like daily and weekly expenses
•Manage relevant menu items to access the features.
*/

struct PersonalExpenses
{
    struct ExpenseDate
    {
        struct Value
        {
            struct expenses
            {
                int TransportCosts, MealCost, EntertainmentCost, HousingCost;
            };
            expenses DailyExpenses;
        };
        struct Days
        {
            Value Days[7];
        };
        struct Week
        {
            Days Week[4];
        };
        struct Month
        {
            Week Month[12];
        };
        Month Year;
    };
    ExpenseDate PersonalExpenses;
} User;

int main()
{

    for (int M = 0; M < 12; M++)
    {
        for (int W = 0; W < 4; W++)
        {
            for (int D = 0; D < 7; D++)
            {   std::cout<<
                User.PersonalExpenses.Year.Month[M].Week[W].Days[D].DailyExpenses.EntertainmentCost<<
                User.PersonalExpenses.Year.Month[M].Week[W].Days[D].DailyExpenses.HousingCost<<
                User.PersonalExpenses.Year.Month[M].Week[W].Days[D].DailyExpenses.MealCost<<
                User.PersonalExpenses.Year.Month[M].Week[W].Days[D].DailyExpenses.TransportCosts;
            }
        }
    }
}
