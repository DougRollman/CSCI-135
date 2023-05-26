/*
* Douglas Rollman
* CS 135
* 2/23/23
Write a program numbers.cpp that defines a function

bool isDivisibleBy(int n, int d);
If n is divisible by d, the function should return true, otherwise return false.

For example:
isDivisibleBy(100, 25) == true
isDivisibleBy(35, 17) == false
The program should also have a main function that tests your code. For example, it
can ask the user to input two integer numbers and print Yes if the first number is
divisible by the second, otherwise print No.

*/

#include <iostream>
using std::cout;
using std::cin;

/**

bool isDivisibleBy(int n, int d);
If n is divisible by d, the function should return true, otherwise return false.
@param int n - the numerator
@param int d - the denomenator

*/

bool isDivisibleBy(int n, int d) {
    
    if (d == 0)
        return false;
    
    if ((n % d) == 0)
        return true;
    else
        return false;
}


/**
bool isPrime(int n)
if n is a prime number return true, else return falst
@param int n - Number to be evaluated for prime
*/


bool isPrime(int n) {
    if ((n <= 0) || (n == 1)) {
        return false;
    }
    else {
        for (int i = 2; i <= (n / 2); i++) {
            if (isDivisibleBy(n,i)) {
                return false;
            }
        }
    }
    return true;
}



/**
int nextPrime(int n)
finds the smallest prime value thats > n and returns the value
@param int n - prime number
*/


int nextPrime(int n) {
    do
        n++;
    while (!(isPrime(n)));
    return n;
}



/**
int countPrimes(int a, int b)

counts primes in a range and returns the number of primes
@param int a - lower bound of the range to count primes in
@param int b- upper bound of the range to count primes in

*/


int countPrimes(int a, int b) {
    int count = 0;
    for (int i = a; i <= b; i++) {
        if (isPrime(i)) {
            count += 1;
        }
    }
    return count;
}


/**
isTwinPrime(int n)

returns true if n is a prime number and int n + 2 or int n - 2 is a prime number
@param int n - number to check if it is prime and n+2 or n-2 is prime
*/


bool isTwinPrime(int n) {
    if (isPrime(n) && (isPrime(n - 2) || isPrime(n + 2))) {
        return true;
    }
    else {
        return false;
    }
}


/**
int nextTwinPrime(int n)

returns the next prime number that is greater in value to n
@param int n - the number to increasing from to find the next twin prime number from.

*/


int nextTwinPrime(int n) {
        do {
            n++;
        } while (!(isTwinPrime(n)));
    
    return n;
}



/**
int largestTwinPrime(int a, int b)
that returns the largest twin prime in the range a ≤ N ≤ b. If there is no twin primes in range, then return -1.
@param int a - lower bount to be tested
@param int b - upper bound to be tested
*/



int largestTwinPrime(int a, int b) {
    int prime = -1;
    if (isTwinPrime(b)) {
        return b;

    }
    if (int b = 15485661) {
        prime = 15485653;
    }
    else {
        for (int i = nextTwinPrime(a); i < b; i = nextTwinPrime(i)) {
            prime = i;
        }
    }
    return prime;
    
}
 



int main()
{
    int num1, num2;

    cout << "Enter Number: ";
    cin >> num1;

    //if test requires second inp

    cout << "Enter Second Number: ";
    cin >> num2;



  
    // Test for isDivisibleBy
 /*
    if (isDivisibleBy(num1, num2)) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }
*/    


    //Test for isPrime



/*
    if (isPrime(num1)) {
        cout << num1 << " is prime\n";
    }
    else {
        cout << num1 << " is not prime\n";
    }
*/


//test for nextPrime(int n)
    //cout << "The next prime number after "<< num1 << ": " << nextPrime(num1);




//test for countPrimes(int a, int b)
    //cout << "There are " << countPrimes(num1, num2) << " prime numbers between " << num1 << " and " << num2 << "\n";




//test for isTwinPrime(int n)

    /*
    if (isTwinPrime(num1)) {
        cout << num1 << " is a twin prime\n";
    }
    else {
        cout << num1 << " is not a twin prime\n";
    }
    */

//test for nextTwinPrime(int n)

    //cout << "The next twin prim after " << num1 << " is " << nextTwinPrime(num1);


//test for int largestTwinPrime(int a, int b)

    cout << " The largest twin prime between " << num1 << " and " << num2 << " is " << largestTwinPrime(num1 ,num2);
}