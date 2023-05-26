/*
Douglas Rollman
Course : CSCI - 136
Genady Maryash
Assignment : Lab2A

--------------------------------------------------------------------------------------
Assignment Lab 2C

Write a program edit-array.cpp that creates an array of 10 integers, and provides the
user with an interface to edit any of its elements. Specifically, it should work as follows:

    1.Create an array myData of 10 integers.
    2.Fill all its cells with value 1 (using a for loop).
    3.Print all elements of the array on the screen.
    4.Ask the user to input the cell index i, and its new value v.
    5.If the index i is within the array range (0 = i < 10), update the asked cell, myData[i] = v,
    and go back to the step 3. Otherwise, if index i is out of range, the program exits.
The repetition of the steps 3-4-5 can be implemented with a do while loop:

        // make array and fill it with 1
        do {
                // print the array
                // get i and v from the user
                // if i is good, update the array at index i
            } while (...); // if the index was good, repeat

The program should keep running until the user inputs an out-of-range (invalid) index.

Example:

$ ./edit-array

1 1 1 1 1 1 1 1 1 1

Input index: 8
Input value: 99

1 1 1 1 1 1 1 1 99 1

Input index: 0
Input value: 300

300 1 1 1 1 1 1 1 99 1

Input index: 10
Input value: 5

Index out of range. Exit.


*/

#include <iostream>
using namespace std;

int main()
{
    int myData[111];
    int value;
    int index;

    for (int i = 0; i < 10; i++) {
        myData[i] = 1;
    }
   
    do {
        for (int i = 0; i < 10; i++) {
            cout << myData[i] << " ";
        }
        cout << "\n";
        cout << "Enter index: ";
        cin >> index;
        cout << "Enter value: ";
        cin >> value;
        myData[index] = value;
    } while ((index < 10) && (index >= 0));

    cout << "Index out of range. Exit.";
}