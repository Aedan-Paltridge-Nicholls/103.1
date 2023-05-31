#include <iostream>
#include <string>
/*
•Application should allow recording a minimum of three different days expenses. 
•Daily expenses must be calculated and displayed by accessing the “view daily expenses “option. √
•Manage constructor to initialize the members 
•Weekly expenses should be calculated and displayed √
•Generate daily reports and weekly reports
•Manage structure array to record multiple days expenses √
•Manage functions to get input and generate reports like daily and weekly expenses
•Manage relevant menu items to access the features.
*/
using namespace std;
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
    bool run = true;
    
    while (run == true)
    {
        int input;
        cout << "See daily Expenses [1]\n"
             << "See Weekly Expenses [1]\n"
             << "Add daiy expenses[3]\n";
        cin >> input;
        switch (input)
        {
            case 1:
            {
                int m, w, d;
                cout << "\nFor what date\n"
                    << "\nMonth of the year 1-12\n";
                cin >> m;
                cout << "\nWeek of the Month 1-4\n";
                cin >> w;
                cout << "\nDay of the Week 1-7\n";
                cin >>d;
                cout << "\nDaily expenses of :"<<d<<'-'<<w<<'-'<<m<<"\n$"<<
                User.PersonalExpenses.Year.Month[m].Week[w].Days[d].DailyExpenses.EntertainmentCost +
                User.PersonalExpenses.Year.Month[m].Week[w].Days[d].DailyExpenses.HousingCost +
                User.PersonalExpenses.Year.Month[m].Week[w].Days[d].DailyExpenses.MealCost +
                User.PersonalExpenses.Year.Month[m].Week[w].Days[d].DailyExpenses.TransportCosts<<endl;
            }
            break;
            case 2:
            {
                int m, w, d,Cost=0;

                cout << "\nFor what date\n"
                    << "\nMonth of the year 1-12\n";
                cin >> m;
                cout << "\nWeek of the Month 1-4\n";
                cin >> w;
                cout << "\nDaily expenses of Week"<<w<<"-"<<m<<"\n $";
                for (int  i = 0; i < 7; i++)
                { Cost +=
                    User.PersonalExpenses.Year.Month[m].Week[w].Days[i].DailyExpenses.EntertainmentCost +
                    User.PersonalExpenses.Year.Month[m].Week[w].Days[i].DailyExpenses.HousingCost +
                    User.PersonalExpenses.Year.Month[m].Week[w].Days[i].DailyExpenses.MealCost +
                    User.PersonalExpenses.Year.Month[m].Week[w].Days[i].DailyExpenses.TransportCosts;
                }
                cout << Cost;
                
            }
            break;
            case 3:
            {   int m, w, d,e;
                cout << "\nFor what date\n"
                    << "\nMonth of the year 1-12\n";
                cin >> m;
                cout << "\nWeek of the Month 1-4\n";
                cin >> w;
                cout << "\nDay of the Week 1-7\n";
                cin >>d;
                cout <<"what Expense\n"<<"\nEntertainment[1]"<<"\nHousing[2]"<<"\nMeal[3]"<<"\nTransport[4]";
                cin >> e;
                switch (e)
                {
                case 1:
                    {cout << "\nWhat Amount\n";
                        cin >>  User.PersonalExpenses.Year.Month[m].Week[w].Days[d].DailyExpenses.EntertainmentCost;
                    }
                    break;
                case 2:
                    {cout << "\nWhat Amount\n";
                        cin >>  User.PersonalExpenses.Year.Month[m].Week[w].Days[d].DailyExpenses.HousingCost;
                    }
                    break;
                    case 3:
                    {cout << "\nWhat Amount\n";
                        cin >>  User.PersonalExpenses.Year.Month[m].Week[w].Days[d].DailyExpenses.MealCost;
                    }
                    break;
                    case 4:
                    {cout << "\nWhat Amount\n";
                        cin >>  User.PersonalExpenses.Year.Month[m].Week[w].Days[d].DailyExpenses.TransportCosts;
                    }
                    break;
                    
                default: run = false;
                    break;
                }

                


            }
            break;
            default:
                break;
        }
    } 
}
            

