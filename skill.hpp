/*
Douglas Rollman
CSIC 135
Project 3A

Class initialization for Skill

*/


#pragma once
#ifndef SKILL_HPP
#define SKILL_HPP

#include <string>

/*
- The name of the skill // a string
- The description of the skill // string
- The total number of times the skill can be used // int
- An integer that represents the specialty of the skill (0, 1 or 2) // int
*/

class Skill {
private:
	std::string name;
	std::string description;
	int totalUses;
	int specialty;
public:
    /*
    @post       :   Initializes the name and
                    description of the skill as
                    "Undefined". Initializes the
                    total uses of the skill and
                    the skill specialty as -1
*/
    Skill();

    /*
    @post       :   Parameterized constructor that
                    sets the corresponding data members
                    equal to the respective parameters
*/
    Skill(std::string name, std::string description, int specialty, int uses);
    /*
        @return     :   name of the skill
    */
    std::string getName();
    /*
        @return     :   description of the skill
    */
    std::string getDescription();
    /*
        @return     :   total uses of the skill
    */
    int getTotalUses();
    /*
        @return     :   specialty of the skill
    */
    int getSpecialty();
    /*
        @post       :   set the name of the skill
                        equal to the given parameter
    */
    void setName(std::string name);
    /*
        @post       :   set the description of the skill
                        equal to the given parameter
    */
    void setDescription(std::string description);
    /*
        @post       :   set the total uses of the skill
                        equal to the given parameter
    */
    void setTotalUses(int uses);
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
    bool setSpecialty(int specialty);
};
#endif