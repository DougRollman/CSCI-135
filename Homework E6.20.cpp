/*
E6.20Write a function

vector<int> merge_sorted(vector<int> a, vector<int> b)
that merges two sorted vectors, producing a new sorted vector. Keep an index into each vector, indicating how much of it has been processed already.
Each time, append the smallest unprocessed element from either vector, then advance the index. For example, if a is

1 4 9 16

and b is

4 7 9 9 11

then merge_sorted returns the vector

1 4 4 7 9 9 9 11 16
*/



#include <iostream>
#include <vector>
using namespace std;

vector<int> append(vector<int> a, vector<int> b) {
    int loopSize = b.size();

    /*
    if (a.size() > b.size()) {
        loopSize = a.size();
    }
    else {
        loopSize = b.size();
    }
    */
    for (int i = 0; i < loopSize; i++) {
        a.push_back(b[i]);
    }
    return a;
}

// 
vector<int> sort(vector<int> a) {
    vector<int> finalVector;
    int loopSize = a.size();
    int i = 0;
    int temp;
    while (i < loopSize) {
        if (i + 1 > loopSize) {
            break;
        }
        for (int j = i; j < loopSize; j++) {
            if (a[j] < a[i]) {
                temp = a[j];
                a[j] = a[i];
                a[i] = temp;
                temp = NULL;
            }
        }
        i++;
    }
    return a;
}

vector<int> merge_sorted(vector<int> a, vector<int> b) {
    vector<int> c = append(a, b);
    return sort(c);
}

int main()
{
    vector<int> sample = {1, 9, 4, 16, 3};
    sample = sort(sample);
    for (int i = 0; i < sample.size(); i++) {
        cout << sample[i] << endl;
    }
}