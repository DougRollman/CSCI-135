/*
Douglas Rollman
CSIC 135
Project 3A

function definitions for profemon class

*/

#include "trainer.hpp"
#include "department.hpp"
#include "skill.hpp"
#include "profemon.hpp"
#include <string>
#include <iostream>
/*

private member variables

private:
    std::string name;
    int experience;
    double max_health;
    int specialty;
    Skill skills[3];
*/

/*
   @post       :   Initializes the name of the Profémon
                   as "Undefined"
*/
Profemon::Profemon() {
    this->name = "Undefined";
    this->experience;
    this->max_health;
    this->requiredExperience;
    this->specialty;
    this->level;
    Skill skills[] = { Skill(), Skill(), Skill() };
}
/*
    @post       :   Initializes the name, max health
                    and specialty as the corresponding
                    parameters. Set the required
                    experience equal to 50.
                    Initializes the current experience
                    and level as 0
*/
Profemon::Profemon(std::string name, double max_health, Specialty specialty) {
    this->name = name;
    this->max_health = max_health;
    this->experience = 0;
    this->requiredExperience = 50;
    this->specialty = specialty;
    this->level = 0;
    Skill skills[] = { Skill(), Skill(), Skill() };
}
/*
    @return     :   name of the Profémon
*/
std::string Profemon::getName() {
    return this->name;
}
/*
    @return     :   specialty of the Profémon
*/
Specialty Profemon::getSpecialty() {
    return this->specialty;
}
/*
    @return     :   level of the Profémon
*/
int Profemon::getLevel() {
    return this->level;
}
/*
    @return     :   maximum health of the Profémon
*/
double Profemon::getMaxHealth() {
    return this->max_health;
}
/*
    @post       :   set the name of the Profémon
                    equal to the given parameter
*/
void Profemon::setName(std::string name) {
    this->name = name;
}
/*
    @param      :   experience points earned by the Profémon
    @post       :   Increase the Profémon's level based on
                    the given 'exp'. The Profémon will level
                    up if it reaches the required experience.
                    Depending on the Profémon's specialty,
                    the required experience goes up by a certain
                    amount everytime the Profémon levels up.
                    'ML' required experience goes up by 10,
                    'SOFTWARE' goes up by 15, and 'HARDWARE'
                    goes up by 20. Make sure to update the
                    required, current experience and level
                    private data members accordingly. The given
                    'exp' can result in the Profémon leveling
                    up multiple times

  For example   :   starting at lvl 0, calling 'levelUp(115)'
                    on different types of Profémon would result
                    in the following:

                    ML:
                      - new level: 2
                      - current exp: 5
                      - required exp: 70

                    SOFTWARE:
                      - new level: 2
                      - current exp: 0
                      - required exp: 80

                    HARDWARE:
                      - new level: 1
                      - current exp: 65
                      - required exp: 70

                    As stated above, each specialty has
                    a different speed of leveling up
*/
void Profemon::levelUp(int exp) {
    experience += exp;
    while (experience >= requiredExperience) {
        experience -= requiredExperience;
        level++;
        switch (specialty) {
        case Specialty::ML:
            requiredExperience += 10;
            break;
        case Specialty::SOFTWARE:
            requiredExperience += 15;
            break;
        case Specialty::HARDWARE:
            requiredExperience += 20;
            break;
        }
    }
}
/*
    @param      :   the skill slot or index
    @param      :   the new skill to be learned
    @return     :   return 'true' if the skill has been successfully
                    learned. Return 'false' if 'slot' parameters is
                    not within the valid range(0,1,2) or the
                    specialty of the 'skill' does not match
                    the specialty of the Profémon
    @post       :   if the given slot is valid(0,1,2) and the
                    skill specialty matched with the Profémon,
                    add the 'skill' to the 'slot' index of the
                    learned skills array
*/
bool Profemon::learnSkill(int slot, Skill skill) {
    if (slot < 0 || slot > 2) {
        return false;
    }
    if (skill.getSpecialty() != specialty) {
        return false;
    }
    skills[slot] = skill;
    return true;
}
/*
    @param      :   bool indicating whether or not the Profémon's
                    skills should be printed
    @post       :   Prints the Profémon's information in a
                    specific format. Additionally, lists
                    the Profémon's skills if the given
                    'print_skills' parameter is true. Only
                    print the skills that are not "Undefined"
Format:
(ProfemonName) [(Specialty)] | lvl (Level) | exp (CurrentExp)/(RequiredExp) | hp (MaxHP)
    (SkillNameSlot0) [(Uses)] : (description of skill in slot 0)
    (SkillNameSlot1) [(Uses)] : (description of skill in slot 1)
    (SkillNameSlot2) [(Uses)] : (description of skill in slot 2)

For example:
Maryash [SOFTWARE] | lvl 2 | exp 30/80 | hp 13500
    OOP [30] : a programming paradigm based on the concept of objects
    Vector [30] : a c++ dynamic array library
    Pointer [10] : a pointer stores a memory address

Note: There are four spaces before the each line of skills.
      The last line prints an endline.
*/
void Profemon::printProfemon(bool print_skills) {
    std::cout << name << " [";
    switch (this->specialty) {
    case 0:
        std::cout << "ML";
        break;
    case 1:
        std::cout << "SOFTWARE";
        break;
    case 2:
        std::cout << "HARDWARE";
        break;
    }
    std::cout << "] | lvl " << level
        << " | exp " << experience << "/" << requiredExperience << " | hp " << max_health << std::endl;
    if (print_skills) {
        for (int i = 0; i < 3; i++) {
            if (skills[i].getName() != "Undefined") {
                std::cout << "    " << skills[i].getName() << " [" << skills[i].getTotalUses() << "] : "
                    << skills[i].getDescription() << std::endl;
            }
        }
    }
}

