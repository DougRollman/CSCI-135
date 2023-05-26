/*
*********** The task ***********

Write a program leap.cpp that asks the user to input an integer representing a year number (1999, 2016, etc.).
If the input year is a leap year according to the modern Gregorian calendar, it should print Leap year, otherwise,
print Common year.

In the modern Gregorian calendar, a year is a leap year if it is divisible by 4, but century years are not leap years
unless they are divisible by 400. Here is the pseudocode:

if (year is not divisible by 4) then (it is a common year)
else if (year is not divisible by 100) then (it is a leap year)
else if (year is not divisible by 400) then (it is a common year)
else (it is a leap year)

This means that 2012, 2016, 2020, and 2040 are all leap years.
However, the century years 1800, 1900, 2100, 2200, 2300 and 2500 are NOT.
Yet, 2000, 2400, 2800 are still leap years.

***********Example 1***********
$ ./leap
Enter year: 2016

Leap year

***********Example 2***********

$ ./leap
Enter year: 2017

Common year
*/

#include<iostream>
using namespace std;


int main()
{

    int year;
    cout << "Enter year:";
    cin >> year;
    cout << endl;

    /*
    
    ********** Psudocode **********
    if (year is not divisible by 4) then (it is a common year)
    else if (year is not divisible by 100) then (it is a leap year)
    else if (year is not divisible by 400) then (it is a common year)
    else (it is a leap year)

    
    */

    if ((year % 4) != 0)
        cout << "Common year";
    else if ((year % 100) != 0)
        cout << "Leap year";
    else if ((year % 400) != 0)
        cout << "Common year";
    else 
        cout << "Leap year";
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
