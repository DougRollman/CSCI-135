﻿/*
Douglas Rollman
Course : CSCI - 136
Genady Maryash
Assignment : Lab2D


Fibonacci numbers is a sequence of numbers that starts with F(0) = 0 and F(1) = 1, with all the following numbers computed
as the sum of two previous ones, F(n) = F(n−1) + F(n−2):

0
1
1 (=1+0)
2 (=1+1)
3 (=2+1)
5 (=3+2)
8 (=5+3)
13 (=8+5)
… and so on …

To make a C++ program to keep track of the previous numbers so that we can compute the new ones, we can use an array of integers:

*/
#include <iostream>
using namespace std;

int main()
{
    int fib[60];
    fib[0] = 0;
    fib[1] = 1;
    
    cout << fib[0] << "\n" << fib[1] << "\n";

    for (i = 2; i < 60; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
        cout << fib[i] << "\n";
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
