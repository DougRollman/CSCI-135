/*
Write a program checkerboard3x3.cpp that asks the user to input width and height and prints a checkerboard of 3-by-3 squares.
(It should work even if the input dimensions are not a multiple of three.)

Example 1:
Input width: 16
Input height: 11

Shape:
***   ***   ***
***   ***   ***
***   ***   ***
   ***   ***   *
   ***   ***   *
   ***   ***   *
***   ***   ***
***   ***   ***
***   ***   ***
   ***   ***   *
   ***   ***   *
Example 2:
Input width: 27
Input height: 27

Shape:
***   ***   ***   ***   ***
***   ***   ***   ***   ***
***   ***   ***   ***   ***
   ***   ***   ***   ***
   ***   ***   ***   ***
   ***   ***   ***   ***
***   ***   ***   ***   ***
***   ***   ***   ***   ***
***   ***   ***   ***   ***
   ***   ***   ***   ***
   ***   ***   ***   ***
   ***   ***   ***   ***
***   ***   ***   ***   ***
***   ***   ***   ***   ***
***   ***   ***   ***   ***
   ***   ***   ***   ***
   ***   ***   ***   ***
   ***   ***   ***   ***
***   ***   ***   ***   ***
***   ***   ***   ***   ***
***   ***   ***   ***   ***
   ***   ***   ***   ***
   ***   ***   ***   ***
   ***   ***   ***   ***
***   ***   ***   ***   ***
***   ***   ***   ***   ***
***   ***   ***   ***   ***
*/

#include <iostream>
using namespace std;


int main()
{
    int height, width;
    int SIZE = 3;

    cout << "Input width: ";
    cin >> width;
    cout << "\nInput height: ";
    cin >> height;
    cout << "\n";
    for (int h = 0; h < height; h++) {
        if ((h % 6) <= 2) {
            for (int w = 0; w < width; w++) {
                if ((w % 6) <= 2)
                    cout << "*";
                else
                    cout << " ";
            }
        }
        else {
            for (int w = 0; w < width; w++) {
                if ((w % 6) <= 2)
                    cout << " ";
                else
                    cout << "*";
            }
        }
        cout << "\n";
    }
}

