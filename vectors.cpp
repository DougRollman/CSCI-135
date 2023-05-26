/*
Douglas Rollman
CSCI 135
Lab 12A

Task A: The easy one
A big benefit of vectors is their ability to be returned from functions. For this task,
program a function called vector<int> makeVector(int n) that returns a vector of n integers
that range from 0 to n-1. Call your program vectors.cpp. Your function must be implemented outside
the main function and must return a vector.
*/


#include <iostream>
#include <vector>

using namespace std;
/*
vector<int> v; // creates a vector of int called v

vector<int> v;
v.push_back(10);
v.push_back(20);
v.push_back(30);

// v now contains elements [10, 20, 30]

*/
vector<int> makeVector(int n) {
    vector<int> k;
    for (int i = 0; i < n; i++) {
        k.push_back(i);
    }
    return k;
}


int main()
{
    std::cout << "Hello World!\n";
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
