/*
Define a structure Triangle that contains three Point members.
Write a function that computes the perimeter of a Triangle.
Write a program that reads the coordinates of the points,
calls your function, and displays the result.
*/

#include <iostream>
#include <math.h>



struct Point
{
    double x;
    double y;
};

struct Triangle
{
    Point a;
    Point b;
    Point c;
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

double perimeter(Triangle tri) {
    double sideA = distance(tri.a, tri.b);
    double sideB = distance(tri.b, tri.c);
    double sideC = distance(tri.c, tri.a);
    double perimiterABC = sideA + sideB + sideC;
    
    return perimiterABC;

}
int main()
{

}