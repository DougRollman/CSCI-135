/*
Write a program cross.cpp that asks the user to input the shape size, and prints a diagonal cross of that dimension.

Example:
Input size: 8

Shape:
*      *
 *    *
  *  *
   **
   **
  *  *
 *    *
*      *

*/

#include <iostream>
using namespace std;

int main()
{
    int size;

    cout << "Input size: ";
    cin >> size;
    cout << "\n";

    for (int col = 0; col < size; col++) {
        for (int row = 0; row < size; row++) {
            if ((row == col) || (row == ((size - col)-1)))
                cout << "*";
            else
                cout << " ";
        }
        cout << "\n";
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
