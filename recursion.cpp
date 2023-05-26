/*
Alice and Bob inherited a collection of paintings. However, they will receive it only if the collection can be divided into two parts of exactly equal price.
(Otherwise, it will be donated to a local art museum.)

Is the collection divisible into two exactly equal halves? We have to find the answer.

The prices of the paintings are provided as an array of integers. For example:

int prices [] = {10, 15, 12, 18, 19, 17, 13, 35, 33};
Here, the total sum is 172, so each person should receive the sum of 86. In this specific example, a solution exists,
it is the following partition: (10 + 15 + 12 + 19 + 17 + 13) = (18 + 35 + 33) = 86.

How to solve the problem recursively?
Consider the example above. Is it possible to divide [10, 15, 12, 18, 19, 17, 13, 35, 33] into sums of 86 and 86?

Each item should go either to Alice or to Bob. Let’s take the first item, 10. Should we give it to Bob or Alice? In either case, there can be a solution. So, let’s try both options:



If we can give 10 to Alice, and the rest can be divided so that she gets 76 and Bob gets 86, then a solution exists (and Alice gets 10).

Also, if we can give 10 to Bob and the rest can be divided so that he gets 76 and Alice gets 86, then the solution also exists (and Bob gets 10).

Otherwise, there is no solution.

Programming task
In the same program, write a function:

bool divisible(int *prices, int size);
which returns true if the collection is divisible, and false otherwise. The prices are provided in the array prices, and size is the number of items in the array.

Your function should not allocate new memory dynamically. Pass the same array data into recursive function calls. If you need more variables such as left and right boundary variables,
or the amounts that should be given to Alice and Bob, make a helper function with any necessary extra variables.

(It is possible to make the program to actually print out the solution, who gets which item. For that, in each of the YES branches, once you know that a solution to the subproblem exists,
print the current item and the name of the person who gets it.)

This is not a simple task, but if you can do it, this is great!
*/


#include <iostream>
#include <string>
using namespace std;

void printRange(int left, int right) {
    if (left > right) {
        return;
    }
    else {
        cout << left << " ";
        return printRange((left + 1), right);
    }
}

int sumRange(int left, int right) {
    if (left > right) {
        return 0;
    }
    else if (left == right) {
        return left;
    }
    else {
        return (left + sumRange((left + 1), right));
    }
}

int sumArray(int* arr, int size) {
    if (size == 0) {
        return 0;
    }
    else {
        return *arr + sumArray((arr + 1), (size - 1));
    }
}

bool isAlphanumeric(string s) {
    if (s.empty()) {
        return true;
    }
    if (!isalnum(s[0])) {
        return false;
    }
    return isAlphanumeric(s.substr(1));
}

bool nestedParens(string s) {
    if (s.empty()) {
        return true;
    }
    if ((s.size() % 2) == 1) {
        return false;
    }
    if(s[0] == '(' && s[s.size() - 1] == ')'){
        return nestedParens(s.substr(1, (s.size() - 2)));
    }
    else {
        return false;
    }
}

bool inheritanceSplit(int* prices, int size, int alice, int bobby, int count) {
    if (size == count) {//base case, if size == count then theres no more paintings to distribute
        if (alice == bobby) {//checking that alice and bobby have equal values
            return true;// returning true because they have equal values
        }
        else {// I don't think the program would get this far, but just in case it has and the values aren't equal it returns false
            return false;
        }
    }

    // add the painting to alices total if possible
    if (inheritanceSplit(prices, size, alice + prices[count], bobby, count + 1)) {
        return true;
    }

    // add the painting to bobby's total if possible
    if (inheritanceSplit(prices, size, alice, bobby + prices[count], count + 1)) {
        return true;
    }

    // if you can't add it to bobby or alice's total then there is no possible solution and return false
    return false;
}

bool divisible(int* prices, int size) {
    int total = sumArray(prices, size);
    if ((total % 2) == 1) {
        return false;
    }
    return inheritanceSplit(prices, size, 0, 0, 0);
    
    
}

int numDigits(int n) {
    if (n == 0) {
        return 0;
    }
    return 1 + numDigits(n / 10);
}

int main(){

    int prices[] = { 10, 15, 12, 18, 19, 17, 13, 35, 33 };

    cout << numDigits(12345);
}
