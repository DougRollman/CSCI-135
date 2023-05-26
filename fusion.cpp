/*
Douglas Rollman
CSIC 135
Lab 12C

Make a program called fusion.cpp that implements the function void gogeta(vector<int> &goku, vector<int> &vegeta) that appends elements of the second vector into the first and empties the second vector. For example:

vector<int> v1{1,2,3};
vector<int> v2{4,5};

gogeta(v1, v2); // v1 is now [1,2,3,4,5] and v2 is empty.

*/



#include <iostream>
#include <vector>

using namespace std;

void gogeta(vector<int>&v1, vector<int>&v2) {

    int loopSize = v2.size();
    for (int i = 0; i < loopSize; i++) {
     v1.push_back(v2[i]);
    }
    v2.clear();
}

int main()
{
    vector<int> v1{ 1,2,3 };
    vector<int> v2{ 4,5 };

    gogeta(v1, v2); // v1 is now [1,2,3,4,5] and v2 is empty.
    for (int i = 0; i < v1.size(); i++) {
        cout << v1[i] << endl;
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
