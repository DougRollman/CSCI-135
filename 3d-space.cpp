/*
A point in 3D space can be represented using three coordinates. In Cartesian coordinate system these coordinates are called (x,y,z), describing the position of the point along the three orthogonal axes:



The origin of the coordinate system is denoted by O and has coordinates (0,0,0).

A point P=(x,y,z), together with the origin, defines a 3D vector OP. The distance from O to P, or in other words, the length of the vector OP can be computed using the euclidean distance formula:

Length of the vector
O
P
=
√
x
2
+
y
2
+
z
2
We are provided with a class type that represents coordinates in 3D:

class Coord3D {
public:
    double x;
    double y;
    double z;
};
Write a program 3d-space.cpp, in which you define a function length() that receives the coordinates of a point P passed as a pointer, and computes the distance from the origin to the point P:

double length(Coord3D *p);
A usage example:

int main() {
    Coord3D pointP = {10, 20, 30};
    cout << length(&pointP) << endl; // would print 37.4166
}
Notice that we pass the memory address &pointP, where the object of this class is located. The function should dereference this address to get the corresponding fields x, y, and z for computing the length.
*/
#include <iostream>
#include <math.h>
using namespace std;

class Coord3D {
public:
    double x;
    double y;
    double z;
};

// allocate memory and initialize
Coord3D* createCoord3D(double x, double y, double z) {
    Coord3D* block = new Coord3D;
    block->x = x;
    block->y = y;
    block->z = z;
    return block;
}

// free memory
void deleteCoord3D(Coord3D* p) {
    delete p;
}

double length(Coord3D *p) {
    
    double l = p->x;
    double w = p->y;
    double h = p->z;
    double l_squared = pow(l, 2);
    double w_squared = pow(w, 2);
    double h_squared = pow(h, 2);
    double total = l_squared + h_squared + w_squared;
    total = sqrt(total);
    return total;
}

Coord3D* fartherFromOrigin(Coord3D* p1, Coord3D* p2) {
    double p1_length = length(p1);
    double p2_length = length(p2);
    if (p1_length > p2_length) {
        return p1;
    }
    else {
        return p2;
    }
}

void move(Coord3D* ppos, Coord3D* pvel, double dt) {
    ppos->x = ppos->x + pvel->x * dt;
    ppos->y = ppos->y + pvel->y * dt;
    ppos->z = ppos->z + pvel->z * dt;


}

int main() {
    double x, y, z;
    cout << "Enter position: ";
    cin >> x >> y >> z;
    Coord3D* ppos = createCoord3D(x, y, z);

    cout << "Enter velocity: ";
    cin >> x >> y >> z;
    Coord3D* pvel = createCoord3D(x, y, z);

    move(ppos, pvel, 10.0);

    cout << "Coordinates after 10 seconds: "
        << (*ppos).x << " " << (*ppos).y << " " << (*ppos).z << endl;

    deleteCoord3D(ppos); // release memory
    deleteCoord3D(pvel);
}