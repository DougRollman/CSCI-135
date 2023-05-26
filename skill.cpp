/*
Douglas Rollman
CSIC 135
Project 3A

Function definitions for Skill class

*/


#include "skill.hpp"
/*
    @post       :   Initializes the name and
                    description of the skill as
                    "Undefined". Initializes the
                    total uses of the skill and
                    the skill specialty as -1
*/
Skill::Skill() {
    this->name = "Undefined";
    this->description = "Undefined";
    this->specialty = -1;
    this->totalUses = -1;
}

/*
   @post       :   Parameterized constructor that
                   sets the corresponding data members
                   equal to the respective parameters
*/
Skill::Skill(std::string name, std::string description, int specialty, int uses) {
    this->name = name;
    this->description = description;
    this->specialty = specialty;
    this->totalUses = uses;
}
/*
    @return     :   name of the skill
*/
std::string Skill::getName() {
    return this->name;
}
/*
    @return     :   description of the skill
*/
std::string Skill::getDescription() {
    return this->description;
}
/*
    @return     :   total uses of the skill
*/
int Skill::getTotalUses() {
    return this->totalUses;
}
/*
    @return     :   specialty of the skill
*/
int Skill::getSpecialty() {
    return this->specialty;
}
/*
    @post       :   set the name of the skill
                    equal to the given parameter
*/
void Skill::setName(std::string name) {
    this->name = name;
}
/*
    @post       :   set the description of the skill
                    equal to the given parameter
*/
void Skill::setDescription(std::string description) {
    this->description = description;
}
/*
    @post       :   set the total uses of the skill
                    equal to the given parameter
*/
void Skill::setTotalUses(int uses) {
    this->totalUses = uses;
}
/*
    @return     :   Return 'true' if the given parameter
                    is either 0, 1 or 2. Otherwise,
                    return 'false'
    @post       :   set the specialty of the skill
                    equal to the given parameter only
                    if the given parameter is valid (0,1,2)
                    Return 'true' if the specialty
                    is successfully updated
*/
bool Skill::setSpecialty(int specialty) {
    this->specialty = specialty;
    return true;
}