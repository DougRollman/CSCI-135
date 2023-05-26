/*
Before we make a program that indents source code files, let’s make a program that unindents them.

Start by writing a function

string removeLeadingSpaces(string line);
that takes one line of code as input and returns its copy without leading spaces and tabs:

removeLeadingSpaces("       int x = 1;  ") == "int x = 1;  "
Make use of the function isspace defined in <cctype> to check if a character is a whitespace. Your function should probably iterate over the input string,
skip all spaces, and after it finds the first non-space character, start accumulating the characters into a new string, which will be returned.

Write a program unindent.cpp that reads input from cin and prints out each input line with leading spaces removed.

Example:
To test, create a badly indented file, for instance, called bad-code.cpp:

                int main(){
           // Hi, I'm a program!
int x = 1;
    for(int i = 0; i < 10; i++) {
cout << i;
          cout << endl;
 }
    }
Since our unindent program reads its input from cin, the badly indented text can be fed into it using standard input redirection:

$ ./unindent < bad-code.cpp
int main(){
// Hi, I'm a program!
int x = 1;
for(int i = 0; i < 10; i++) {
cout << i;
cout << endl;
}
}
*/

#include <iostream>
#include<string>
#include<cctype>

using namespace std;

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
    string words;
    while (getline(cin, words)) {
        cout << removeLeadingSpaces(words) << endl;
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
