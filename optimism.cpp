// optimism.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;



vector<int> goodVibes(vector<int> v) // returns [1,2,3,4,6]
{
    vector<int> positiveInts;
    int loopSize = v.size();
    for (int i = 0; i < loopSize; i++) {
        if (v[i] > 0) {
            positiveInts.push_back(v[i]);
        }
    }
    return positiveInts;
}
int main()
{
    vector<int> v{ 1,2,-1,3,4,-1,6 };

    vector<int> k =goodVibes(v); // returns [1,2,3,4,6]
    for (int i = 0; i < k.size(); i++) {
        cout << k[i] << endl;
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
