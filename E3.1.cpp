/*
Douglas Rollman
Course : CSCI - 136
Genady Maryash
Assignment : Homework E3.1

E3.1Write a program that reads an integer and prints whether it is negative, zero, or positive.
*/
#include <iostream>
using namespace std;

int main()
{
	int num;
	cout << "Enter a num: ";
	cin >> num;
	
	if (num < 0)
		cout << "negative";
	else if (num == 0)
		cout << "zero";
	else
		cout << "positive";
}