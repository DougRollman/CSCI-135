/*
Douglas Rollman
2/16/2023
*/
#include <iostream>
#include <cstdlib>
#include <climits>
#include <fstream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::cerr;
using std::string;
using std::ifstream;

int main() {
    string red, green, blue, yellow;

  

    ifstream fin("data.txt");

    string junk;        // new string variable
    getline(fin, junk); // read one line from the file 

    while (fin >> red >> blue >> yellow >> green) {
        // this loop reads the file line-by-line
        // extracting 5 values on each iteration 
        fin.ignore(INT_MAX, '\n'); //skips to the end of line, 
        //ignorring the remaining columns

        cout << red;
        cout << blue; <<
        cout << yellow << "\n";
        cout << green << "\n";
        }
    fclose(fin);
    return 0;
    }

