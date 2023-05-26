/*
Author: Douglas Rollman
Course: CSCI-135
Instructor: Gennadiy Maryash
Assignment: Lab 9 Task A

*/
#include <iostream>
using namespace std;


string * createAPoemDynamically() {
    string *p = new string;
    *p = "Roses are red, violets are blue";
    return p;
}

int main() {
    while(true) {
        string *p;
        p = createAPoemDynamically();
        // assume that the poem p is not needed at this point
        delete p;
    }
}