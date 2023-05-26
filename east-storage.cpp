/*
Douglas Rollman
CS 135
2/9/23


Write a program east-storage.cpp that asks the user to input a string representing the date (in MM/DD/YYYY format), and prints out the East basin storage on that day.

Example
$ ./east-storage
Enter date: 05/20/2018
East basin storage: 80.96 billion gallons
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
    double eastSt, eastEl, westSt, westEl;
    string date, dateInp;

    cout << "Enter a date: ";
    cin >> dateInp;

    ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {
        cerr << "File cannot be opened for reading." << endl;
        exit(1); // exit if failed to open the file
    }
    
    string junk;        // new string variable
    getline(fin, junk); // read one line from the file 

    while (fin >> date >> eastSt >> eastEl >> westSt >> westEl) {
        // this loop reads the file line-by-line
        // extracting 5 values on each iteration 
        fin.ignore(INT_MAX, '\n'); //skips to the end of line, 
        //ignorring the remaining columns 

        if (date == dateInp) {
            cout << "East basin storage: " << eastSt;
        }        
    }
    return 0;
}