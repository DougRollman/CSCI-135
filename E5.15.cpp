//Douglas Rollman
//Cs 150
// 2-23-23

/*
E5.15Write a function sort3(int& a, int& b, int& c) that swaps its three arguments to arrange them in sorted order. For example,

int v = 3;
int w = 4;
int x = 1;
sort3(v, w, x); // v is now 1, w is now 3, x is now 4
Hint: Use multiple calls to the sort2 function of Exercise •• E5.14.
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

void sort3(int& a, int& b, int& c) {
    if ((a > b) && (a > c)) {
        sort2(a, c);
    }
    if ((b > a) && (b > c)) {
        sort2(b, c);
    }
    if ((b < a) && (b < c)) {
        sort2(a,b);
    }
    if ((c < a) && (c < b)) {
        sort2(a,c);
    }
}
int main()
{
    int num1, num2, num3;
    cout << "Enter Number 1: ";
    cin >> num1;
    cout << "Enter Number 2: ";
    cin >> num2;
    cout << "Enter Number 3: ";
    cin >> num3;
    sort3(num1, num2, num3);
    cout << num1 << ", " << num2 << ", " << num3;

    return;

}

