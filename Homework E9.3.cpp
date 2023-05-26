/*
Douglas Rollman
Homework E9.3.cpp
CSCI 135
*/ 
#include <iostream>

using namespace std;

class Circuit {
private:
    int first_switch;
    int second_switch;
public:
    Circuit(int switch1, int switch2) {
        first_switch = switch1 % 2;
        second_switch = switch2 % 2;
    }
    int get_first_switch_state() {
        return first_switch;
    }
    int get_second_switch_state() {
        return second_switch;
    }
    void toggle_first_switch() {
        first_switch = (first_switch + 1) % 2;
    }
    int get_lamp_state() {
        return (first_switch + second_switch) % 2;
    }
    void toggle_second_switch() {
        second_switch = (second_switch + 1) % 2;
    }
};

/*
int get_first_switch_state() // 0 for down, 1 for up
int get_second_switch_state()
int get_lamp_state() // 0 for off, 1 for on
void toggle_first_switch()
void toggle_second_switch()

*/

int main()
{
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
