/*
Author: Douglas Rollman
Course: CSCI-136
Instructor: Proff Maryash
Assignment: Lab6A
Write a program caesar.cpp with functions implementing Caesar cipher encryption:

// A helper function to shift one character by rshift
char shiftChar(char c, int rshift);

// Caesar cipher encryption
string encryptCaesar(string plaintext, int rshift);
The argument rshift is the magnitude of the right shift. For the sake of the lab, you may assume it to be in the range 0 ≤ rshift ≤ 25
(although, implementing it correctly for an arbitrary integer shift is also possible, of course).

Your functions should preserve case, and any non-alphabetic characters should be left unchanged. For example,

encryptCaesar("Way to Go!", 5) == "Bfd yt Lt!"
Feel free to write more additional helper functions when you need them.

The main function should ask the user to input a plaintext sentence, then enter the right shift, and report the ciphertext computed using your
encryption function.

Example:
$ ./caesar

Enter plaintext: Hello, World!
Enter shift    : 10
Ciphertext     : Rovvy, Gybvn!
*/

#include <iostream>
#include <string>
using namespace std;



char shiftChar(char c, int rshift) {
    if (((c >= 'A') && (c <= 'Z'))) {
        c = ((((int)c - 65) + rshift) % 26) + 65;
        return c;
    }
    if ((c >= 'a') && ((c <= 'z'))) {
        c = ((((int)c - 97) + rshift) % 26) + 97;
        return c;

    }
    else {
        return c;
    }
}

string encryptCaesar(string plaintext, int rshift) {
    int size = plaintext.length();
    string encrypted;
    for (int i = 0; i < size; i++) {
        encrypted += shiftChar(plaintext[i], rshift);
    }
    return encrypted;
}




int main()
{
    string inp;
    string encrypted;
    int shift;

    cout << "Enter Plaintext: \n";
    getline(cin, inp);
    cout << "Enter Shift: \n";
    cin >> shift;
    encrypted = encryptCaesar(inp, shift);
    cout << "Cyphertext : " << encrypted;

}
