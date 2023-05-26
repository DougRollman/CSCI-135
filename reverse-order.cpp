/*
Douglas Rollman
CS 135
2/9/23

Write a program reverse-order.cpp which asks the user to input two dates (earlier date then later date). The program should report the West basin elevation for all days in the interval in the reverse chronological order (from the later date to the earlier).

Example:
$ ./reverse-order
Enter earlier date: 05/29/2018
Enter later date: 06/02/2018

06/02/2018  590.32 ft
06/01/2018  590.26 ft
05/31/2018  590.24 ft
05/30/2018  590.23 ft
05/29/2018  590.22 ft
Hint: If for the previous tasks you did not use arrays, here you really have to read the data into arrays first, and only then report them in the required order.
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
    int i = 0;
    int j = 0;
    string dateArray[365];
    double elevArray[365];



    cout << "Enter earlier date: ";
    cin >> dateStart;
    cout << "Enter later date: ";
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
            dateArray[i] = date;
            elevArray[i] = westEl;
            i++;
        }        
        if (date == dateEnd)
            tf = false;         
    }
    for (int j = 0; j < i; j++) {
        cout << dateArray[(i-1)-j] << " " << elevArray[(i-1)-j] << " ft\n";
    }



    return 0;
}