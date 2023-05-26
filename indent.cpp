/*
To count open blocks, we need to count how many curly braces get opened and closed on each line, so we need to count { and }

Write a function

int countChar(string line, char c);
that scans the line and returns the number of occurrences of the character c.

Write a new program indent.cpp that enhances the program from the previous task. As it reads the input line by line, it should also count the number of open and closed { } in it, 
and keep track of how many blocks is currently open at the beginning of each line.

In the listing below, the number of open blocks is shown on the left:

0   int main(){
1   // Hi, I'm a program!
1   int x = 1;
1   for(int i = 0; i < 10; i++) {
2   cout << i;
2   cout << endl;
2   }
1   }
Then instead of printing the number of open blocks, add that number of tabs '\t' at the beginning of each line, and you will get:

int main(){
    // Hi, I'm a program!
    int x = 1;
    for(int i = 0; i < 10; i++) {
        cout << i;
        cout << endl;
        } // <-- closing for loop
    }     // <-- closing main
Notice that the closing curly braces are indented one level further than what they should be.

To fix that, when indenting the line, check its very first character. If it is a closing curly brace }, its indentation level should be reduced by one:

int main(){
    // Hi, I'm a program!
    int x = 1;
    for(int i = 0; i < 10; i++) {
        cout << i;
        cout << endl;
    }
}
*/

#include<iostream>
#include<string>
using namespace std;
//scans the line and returns the number of occurrences of the character c.
int countChar(string line, char c) {
    int size = line.length();
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (line[i] == c) {
            count++;
        }
    }
    return count;
}

string removeLeadingSpaces(string line) {
    int size = line.length();
    bool flag = false;
    string result;
    for (int i = 0; i < size; i++) {
        if (!flag) {
            if (!isspace(line[i])) {
                result += line[i];
                flag = true;
            }
            else {
                continue;
            }
        }
        else {
            result += line[i];
        }
    }
    return result;
}

int main()
{
    string input;
    string indentedString;
    int count = 0;
    bool indentedAlready = false;
    string junk;
    while (getline(cin, input)) {
        junk = removeLeadingSpaces(input);
        if (junk[0] == '}') {
            count--;
            indentedAlready = true;
        }
        for (int i = 0; i < count; i++) {
            cout << '\t';
        }
        if (countChar(input, '{')) {
            count = count + countChar(input, '{');
        }
        if (countChar(input, '}')){
            count = count - countChar(input, '}') + indentedAlready;
            indentedAlready = false;
        }
        cout << removeLeadingSpaces(input) << endl;

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
