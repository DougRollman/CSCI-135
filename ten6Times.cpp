/*
* 
Douglas Rollman
Cs135 
Code Review


Write a C++ program that will print "10" 6 times in one row, for 10 rows.

The output of your program should be:

101010101010
101010101010
101010101010
101010101010
101010101010
101010101010
101010101010
101010101010
101010101010
101010101010


*/

#include <iostream>
using namespace std;

int main()
{
	// declare iteration variables
	int i;
	int j;

	//nested loop that prints 6 times in the inner loop, and creates a new line 10 times in the outer loop
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 6; j++) {
			cout << "10";
		}
		cout << "\n";
	}
}
