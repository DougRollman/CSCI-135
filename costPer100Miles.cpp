/*
 Written By Douglas Rollman
 Class: Cs 135
 Date: 1/26/2023
 

Write a program that asks the user to input
    The number of gallons of gas in the tank
    The fuel efficiency in miles per gallon
    The price of gas per gallon
Then print the cost per 100 miles and how far the car can go with the gas in the tank.
*/



#include <iostream>
using namespace std;

float cost100miles(float eff, float cost) {
    
    //declaring variables
    float gasUsed = 100 / eff;
    // amount used in 100 mile vs the cost of the amount used to get total cost
    float total = gasUsed * cost;

    return total;

}
float distanceTilEmpty(float eff, float numGal) {
    // efficiency times the num of galons available = distance drivable
    float total = eff * numGal;

    return total;
}

int main()
{
    // declaring variables
    float numGal; //num of gallons in the tank
    float eff; //fuel efficiency in miles per gallon
    float cost; // cost per gallon

    
    //Getting input from user and assigning value to declared variables
    cout << "Gallons in tank: ";
    cin >> numGal;
    cout << endl << "Mpg: ";
    cin >> eff;
    cout << endl << "Price per gallon: ";
    cin >> cost;

    // calculate cost per 100 miles
    cout << cost100miles(eff, cost) << endl;
    // calculate distance with gas in tank
    cout << distanceTilEmpty(eff, numGal) << endl;



}