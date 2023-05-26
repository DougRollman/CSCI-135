/*
•• E6.8Write a function

bool equals(int a[], int a_size, int b[], int b_size)
that checks whether two arrays have the same elements in the same order.
*/

#include <iostream>
using namespace std;

bool equals(int a[], int a_size, int b[], int b_size)
{
    bool flag = true;
    if (a_size != b_size) {
        flag = false;
        return flag;
    }
    else {
        for (int i = 0; i < a_size; i++) {
            if (a[i] != b[i]) {
                flag = false;
                return flag;
            }
        }
        return flag;

    }
}

int main()
{
    
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
