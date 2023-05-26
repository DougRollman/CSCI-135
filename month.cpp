// month.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*

Write a program month.cpp that asks the user to input the year and the month (1-12) and prints the number of days in
that month (taking into account leap years). You may not use switch case or arrays even if you know these language
constructs.

Example
$ ./month
Enter year: 2017
Enter month: 5

31 days


*/


#include <iostream>
using namespace std;

int leap(int year)
{
    /*

    ********** Psudocode **********
    if (year is not divisible by 4) then (it is a common year)
    else if (year is not divisible by 100) then (it is a leap year)
    else if (year is not divisible by 400) then (it is a common year)
    else (it is a leap year)


    */

    if ((year % 4) != 0)
        return 1;
    else if ((year % 100) != 0)
        return 2;
    else if ((year % 400) != 0)
        return 1;
    else
        return 2;

/*
return 1 for common year
return 2 for leap
*/
}

int main()
{

    int year, month;
    cout << "Enter year";
    cin >> year;
    cout << endl << "Enter month :";
    cin >> month;

    if ((leap(year) == 1) && (month == 2))
        cout << "28 Days";
    else if ((leap(year) == 2) && (month == 2))
        cout << "29 Days";
    else if ((month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8) || (month == 10) || (month == 12))
        cout << "31 Days";
    else
        cout << "30 Days";
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
