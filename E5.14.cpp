//Douglas Rollman
//Cs 135
//2/23/23

/*
Write a function void sort2(int& a, int& b) that swaps the values of a and b if a is greater than b and otherwise leaves a and b unchanged.
For example,

int u = 2;
int v = 3;
int w = 4;
int x = 1;
sort2(u, v); // u is still 2, v is still 3
sort2(w, x); // w is now 1, x is now 4

*/





#include <iostream>
using std::cout;
using std::cin;

void sort2(int& a, int& b) {
	int c;
	if (a > b) {
		c = a;
		a = b;
		b = c;
	}
}

int main()
{
	/*
	int num1, num2;
	cout << "Enter Number 1: ";
	cin >> num1;
	cout << "Enter Number 2: ";
	cin >> num2;
	cout << num1 << ", " << num2 << "\n";
	sort2(num1, num2);
	cout << num1 << ", " << num2 << "\n";
	*/
	return 0;
}
