/*
Define a structure Point. A point has an x- and a y-coordinate. Write a function double distance(Point a, Point b) that computes the distance from a to b.
Write a program that reads the coordinates of the points, calls your function, and displays the result.
*/

#include <iostream>
#include <math.h>
struct Point
{
    int x;
    int y;
};

double distance(Point a, Point b) {
    double x_value = b.x - a.x;
    x_value = pow(x_value, 2);
    double y_value = b.y - a.y;
    y_value = pow(y_value, 2);
    double result = x_value + y_value;
    result = sqrt(result);
    return result;
}
int main()
{

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
