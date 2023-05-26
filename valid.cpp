/*
Douglas Rollman
Course: CSCI-136
Genady Maryash
Assignment: Lab2A


---------------------------------------------------------------------------------------------------------
Write a program valid.cpp, which asks the user to input an integer in the range 0 < n < 100. 
If the number is out of range, the program should keep asking to re-enter until a valid numberis input.
After a valid value is obtained, print this number n squared.

Example
$ ./valid
Please enter an integer: -10
Please re-enter: 1200
Please re-enter: 100
Please re-enter: 7

Number squared is 49
---------------------------------------------------------------------------------------------------------

*/

#include <iostream>
using std::cout;
using std::cin;

int main()
{
    //initial variable
    int num;
    int numsquared;
    //runs prompt and user input
        cout << "Please enter an integer: ";
        cin >> num;
        // while loop runs until conditions are met
        while ((num <= 0) || (num >= 100)) {
            cout << "Please re-enter an integer: ";
            cin >> num;
        }

        // now that condition for num is met, num is squared and it's value printed.
        numsquared = num * num;
        cout << "Number squared is " << numsquared << "\n";
}

