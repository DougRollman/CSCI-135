/*
* Task F. Upside-down trapezoid
Write a program trapezoid.cpp that prints an upside-down trapezoid of given width and height.

However, if the input height is impossibly large for the given width, then the program should report, Impossible shape!

Example 1:
Input width: 12
Input height: 5

Shape:
************
 **********
  ********
   ******
    ****
Example 2:
Input width: 12
Input height: 7

Impossible shape!
Hint:
You can start with the number of

spaces = 0;
stars = width;
On each line, print that number of spaces followed by that number of stars. After that, the number of spaces gets incremented by 1,
while the number of stars gets decremented by 2:

spaces += 1;
stars -= 2;
*/

#include <iostream>
using namespace std;

int main()
{
    int width, height;
    int spaces = 0;
    int stars = 0;

    cout << "Input width: ";
    cin >> width;
    cout << "\nInput height: ";
    cin >> height;
    cout << "\n";
    if ((width - ((height * 2)-1)) < 0)
        cout << "Impossible Shape";
    else
    {
        for (int h = 0; h < height; h++) {
            for (int i = 0; i < spaces; i++)
                cout << " ";
            for (int j = 0; j < (width + stars); j++)
                cout << "*";
            for (int k = 0; k < spaces; k++)
                cout << " ";
            spaces += 1;
            stars -= 2;
            cout << "\n";
        }
    }

}
