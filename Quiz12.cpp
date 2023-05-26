#include <iostream>
using namespace std;

class Customer {
private:
    string name1;
    string unique_id1;

public:
    Customer() {
        name1 = "";
        unique_id1 = "";
    }
    Customer(string name, string unique_id) {
        name1 = name;
        unique_id1 = unique_id;
    }
    string get_name() {
        return name1;
    }
    string get_unique_id() {
        return unique_id1;
    }
    void set_name(string name) {
        name1 = name;
    }
    void set_unique_id(string unique_id) {
        unique_id1 = unique_id;
    }
};
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
