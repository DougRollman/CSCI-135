/*
E6.18Write a function

vector<int> append(vector<int> a, vector<int> b)
that appends one vector after another.For example, if a is

1 4 9 16

and b is

9 7 4 9 11

then append returns the vector

1 4 9 16 9 7 4 9 11
*/


#include <iostream>
#include <vector>
using namespace std;

vector<int> append(vector<int> a, vector<int> b) {
    int loopSize = b.size();
    
    /*
    if (a.size() > b.size()) {
        loopSize = a.size();
    }
    else {
        loopSize = b.size();
    }
    */
    for(int i = 0; i < loopSize; i++){
        a.push_back(b[i]);
    }
    return a;
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
