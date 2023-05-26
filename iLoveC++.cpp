/*
Douglas Rollman
CS 135

Begin with an introductory comment

Write a program that asks the user for a number using cin >>

Print out tht number of lines that say "I love C++"

*/
#include <iostream>
using namespace std;

int main()
{
	// declaring variables
	int i;
	int num;

	cout << "Enter a number: ";
	cin >> num;

	for (i = 0; i < num; i++)
		cout << "I love C++\n";
}

