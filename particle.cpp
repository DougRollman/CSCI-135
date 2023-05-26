#include <iostream>
#include <math.h>
using namespace std;

class Coord3D {
public:
    double x;
    double y;
    double z;
};

class Particle {
public:
    double x;
    double y;
    double z;
    double vx;
    double vy;
    double vz;
};

// dynamically allocate memory for a particle and initialize it
Particle* createParticle(double x, double y, double z,
    double vx, double vy, double vz) {
    Particle* atom = new Particle;
    atom->x = x;
    atom->y = y;
    atom->z = z;
    atom->vx = vx;
    atom->vy = vy;
    atom->vz = vz;
    return atom;
}

// set its velocity to (vx, vy, vz)
void setVelocity(Particle* p, double vx, double vy, double vz) {
    p->vx = vx;
    p->vy = vy;
    p->vz = vz;
}

// allocate memory and initialize
Coord3D* createCoord3D(double x, double y, double z) {
    Coord3D* block = new Coord3D;
    block->x = x;
    block->y = y;
    block->z = z;
    return block;
}

// get its current position
Coord3D getPosition(Particle* p) {
    Coord3D* particlePOS = createCoord3D(p->x, p->y, p->z);
    return *particlePOS;
}

// update particle's position after elapsed time dt
void move(Particle* p, double dt) {
    p->x = p->x + p->vx * dt;
    p->y = p->y + p->vy * dt;
    p->z = p->z + p->vz * dt;


}
void deleteParticle(Particle* p) {
    delete p;
}


// free memory
void deleteCoord3D(Coord3D* p) {
    delete p;
}

double length(Coord3D* p) {

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
    // make new particle
    Particle* p = createParticle(1.0, 1.5, 2.0, 0.1, 0.2, 0.3);
    double time = 0.0;
    double dt = 0.1;
    while (time < 3.0) {
        // update its velocity
        setVelocity(p, 10.0 * time, 0.3, 0.1);

        // move the particle
        move(p, dt);
        time += dt;

        // reporting its coordinates
        cout << "Time: " << time << " \t";
        cout << "Position: "
            << getPosition(p).x << ", "
            << getPosition(p).y << ", "
            << getPosition(p).z << endl;
    }
    // remove the particle, deallocating its memory
    deleteParticle(p);
}