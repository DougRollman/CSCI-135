/*
Write a program lower.cpp that prints the bottom-left half of a square, given the side length.

Example:
Input side length: 6

Shape:
*
**
***
****
*****
******

*/
#include <iostream>
using namespace std;

int main()
{
    int len;
    cout << "Input side length: ";
    cin >> len;
    cout << "\n";
    for (int height = 0; height < len; height++) {
        for (int width = 0; width < len; width++) {
            if (width <= height)
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
