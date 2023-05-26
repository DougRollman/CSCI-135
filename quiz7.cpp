// quiz7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

void remove_e(string& s) {
    
    
}

int main()
{
    string s;
    cout << "enter string ";
    getline(cin, s);
    remove(s.begin(), s.end(), 'e');
    cout << s;
}

