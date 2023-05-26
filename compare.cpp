/*
Douglas Rollman
CS 135
2/9/23

Write a program compare.cpp that asks the user to input two dates (the beginning and the end of the interval). The program should check each day in the interval and report which basin had higher elevation on that day by printing “East” or “West”, or print “Equal” if both basins are at the same level.

Example:
$ ./compare
Enter starting date: 09/13/2018
Enter ending date: 09/17/2018

09/13/2018 West
09/14/2018 West
09/15/2018 West
09/16/2018 West
09/17/2018 West
Explanation:
Date	East (ft)	West (ft)
09/13/2018	581.94	582.66	West is higher
09/14/2018	581.8	582.32	West is higher
09/15/2018	581.62	581.94	West is higher
09/16/2018	581.42	581.55	West is higher
09/17/2018	581.16	581.2	West is higher
*/
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <climits>

using std::cout;
using std::cin;
using std::endl;
using std::cerr;
using std::string;
using std::ifstream;

int main() {
    double eastSt, eastEl, westSt, westEl;
    string date, dateStart, dateEnd;
    bool tf = false;



    cout << "Enter starting date: ";
    cin >> dateStart;
    cout << "Enter ending date: ";
    cin >> dateEnd;

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
        if (date == dateStart)
            tf = true;
        if (tf) {
            cout << date;
            if (westEl > eastEl)
                cout << " West is higher";
            else
                cout << " East is higher";
            cout << "\n";
        if (date == dateEnd)
            tf = false;      
        }
    



    }
    
    return 0;
}