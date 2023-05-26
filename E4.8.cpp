//  Douglas Rollman
//  CS 135
//  2/9/23

#include <iostream>
using namespace std;

int main()
{
    string word;
    cout << "Enter a string: ";
    cin >> word;
    for (int i = 0; i < word.size(); i++) {
        cout << word[i] << "\n";
    }
   
}

