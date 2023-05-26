/*
$ . / smaller3
Enter the first number : 23
Enter the second number : 76
Enter the third number : 37

The smaller of the three is 23
*/
#include <iostream>
using namespace std;

int main()
{
    int num1, num2, num3;

    cout << "Enter the first number :"; 
    cin >> num1;
    cout << endl << "Enter the second number :" ; 
    cin >> num2;
    cout << endl << "Enter the third number :" ;
    cin >> num3;
    cout << endl;

    if ((num1 < num2) && (num1 < num3))
        cout << "The smaller of the three is " << num1;
    else if ((num2 < num1) && (num2 < num3))
        cout << "The smaller of the three is " << num2;
    else
        cout << "The smaller of the three is " << num3;
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
