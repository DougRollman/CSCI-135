/*



Write a program minmax.cpp that finds the minimum and maximum storage in East basin in 2018.

Example (using made up numbers):
$ ./minmax
minimum storage in East basin: 59.88 billion gallons
MAXimum storage in East basin: 81.07 billion gallons
Hint:
The program should read the file line by line, while keeping track of what is the highest and the lowest storage level in the basin so far. In the end, after reading the entire file, the found values will be the minimum and the maximum storage levels for the entire year.


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


int main()
{
    double eastSt, eastEl, westSt, westEl, minVal, maxVal;
    string date;
    
    minVal = 100000;
    maxVal = 0;

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
        if (eastSt < minVal) {
            minVal = eastSt;
        }
        if (eastSt > maxVal) {
            maxVal = eastSt;
        }
    }
    cout << "minimum storage in East basin: " << minVal << "\n" << "Maximum storage in East basin: " << maxVal;
    return 0;
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
