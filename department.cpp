#include "profemon.hpp"
#include "skill.hpp"
#include "department.hpp"
#include <iostream>

using namespace std;

/*
class MLDepartment : public Trainer {
public:
    MLDepartment(std::vector<Profemon> profemons);
    bool addProfemon(Profemon profemon);
};

class SoftwareDepartment : public Trainer {
public:
    SoftwareDepartment(std::vector<Profemon> profemons);
    bool addProfemon(Profemon profemon);
};

class HardwareDepartment : public Trainer {
public:
    HardwareDepartment(std::vector<Profemon> profemons);
    bool addProfemon(Profemon profemon);
};
*/

MLDepartment::MLDepartment(std::vector<Profemon> profemons) : Trainer(){
    for (int i = 0; i < profemons.size(); i++) {
        if (profemons[i].getSpecialty() == Specialty::ML) {
            addProfemon(profemons[i]);
        }
    }
}
bool MLDepartment::addProfemon(Profemon profemon) {
    if (profemon.getSpecialty() != Specialty::ML) {
        return false;
    }

    return Trainer::addProfemon(profemon);
}

SoftwareDepartment::SoftwareDepartment(std::vector<Profemon> profemons) : Trainer(){
    for (int i = 0; i < profemons.size(); i++) {
        if (profemons[i].getSpecialty() == Specialty::SOFTWARE) {
            addProfemon(profemons[i]);
        }
    }
}
bool SoftwareDepartment::addProfemon(Profemon profemon)  {
    if(profemon.getSpecialty() != Specialty::SOFTWARE) {
        return false;
    }

    return Trainer::addProfemon(profemon);
}
HardwareDepartment::HardwareDepartment(std::vector<Profemon> profemons) : Trainer(){
    for (int i = 0; i < profemons.size(); i++) {
        if (profemons[i].getSpecialty() == Specialty::HARDWARE) {
            addProfemon(profemons[i]);            
        }
    }
}
bool HardwareDepartment::addProfemon(Profemon profemon) {
    if (profemon.getSpecialty() != Specialty::HARDWARE) {
        return false;
    }

    return Trainer::addProfemon(profemon);
}

