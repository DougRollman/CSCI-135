/*


Douglas Rollman
Course : CSCI - 136
Genady Maryash
Assignment : Lab2A

--------------------------------------------------------------------------------------
Assignment Lab 2A 

Write a program print-interval.cpp that asks the user to input two integers L and U 
(representing the lower and upper limits of the interval), and print out all integers
in the range L ≤ i < U separated by spaces. Notice that we include the lower limit, but
exclude the upper limit.


Example

$ ./print-interval
Please enter L: -5
Please enter U: 10

-5 -4 -3 -2 -1 0 1 2 3 4 5 6 7 8 9

--------------------------------------------------------------------------------------

*/


#include <iostream>
using namespace std;

int main()
{
    // declaring lower and upper limits
    int l;
    int u;
    //iteration variable
    int i;
    
    cout << "Please enter L: ";
    cin >> l;
    cout << "Please enter U: ";
    cin >> u;

    for (i = l; i < u; i++)
        cout << i << " ";

    

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
