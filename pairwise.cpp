/*
Douglas Rollman
CSIC 135
Lab 12D

Task D: Pairwise sum
Write a program called pairwise.cpp that implements the function vector<int> sumPairWise(const vector<int> &v1, const vector<int> &v2)
that returns a vector of integers whose elements are the pairwise sum of the elements from the two vectors passed as arguments.
If a vector has a smaller size than the other, consider extra entries from the shorter vectors as 0. Example:

vector<int> v1{1,2,3};
vector<int> v2{4,5};

sumPairWise(v1, v2); // returns [5, 7, 3]

*/


#include <iostream>
#include <vector>

using namespace std;

vector<int> sumPairWise(vector<int>& v1, vector<int>& v2) {
    vector<int> sumPairVector;
    int loopsize, sumPair;
    if (v1.size() > v2.size()) {
        loopsize = v1.size();
    }
    else {
        loopsize = v2.size();
    }
    for (int i = 0; i < loopsize; i++)
    {
        if (i >= v1.size()) {
            sumPairVector.push_back(v2[i]);
        }
        else if (i >= v2.size()) {
            sumPairVector.push_back(v1[i]);
        }
        else {
            sumPairVector.push_back(v2[i] + v1[i]);
        }
    }
    return sumPairVector;
}

int main()
{
    vector<int> v1{ 1,2,3 };
    vector<int> v2{ 4,5 };
    vector<int> v3 = sumPairWise(v1, v2); // returns [5, 7, 3]
    for (int i = 0; i < v3.size(); i++) {
        cout << v3[i] << endl;
    }
}
