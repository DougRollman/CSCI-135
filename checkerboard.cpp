/*


Write a program checkerboard.cpp that asks the user to input width and height and prints a rectangular checkerboard
of the requested size using asterisks and spaces (alternating).

Example:
Input width: 11
Input height: 6

Shape:
* * * * * *
 * * * * *
* * * * * *
 * * * * *
* * * * * *
 * * * * *
Hint:
You used nested loops in the previous task that looked probably like

for (int row = 0; row < height; row++) {
    for (int col = 0; col < width; col++) {

        ...

    }
}
Inside the loops, you can add an if statement that will be conditionally printing asterisk * or (space) depending on the
coordinates row and col.
*/

#include <iostream>
using namespace std;

int main()
{
    int width, height;

    cout << "Enter width: ";
    cin >> width;
    cout << "\nEnter height: ";
    cin >> height;
    cout << "\n";
    for (int row = 0; row < height; row++) {
        if ((row % 2) == 0) {
            for (int col = 0; col < width; col++) {
                if ((col % 2) == 0)
                    cout << "*";
                else
                    cout << " ";
            }
        }
        else {
            for (int col = 0; col < width; col++) {
                if ((col % 2) == 0)
                    cout << " ";
                else
                    cout << "*";
            }
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
