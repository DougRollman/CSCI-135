/*
Author: Douglas Rollman
Course: CSCI-136
Instructor: Proff Maryash
Assignment: Lab6C
Write a program caesar.cpp with functions implementing Caesar cipher encryption:

Write a program vigenere.cpp. It should contain a function encryptVigenere implementing this cipher:

string encryptVigenere(string plaintext, string keyword);
You may assume that the keyword contains only lowercase alphabetic characters a - z.

The main should implement a testing interface similar to the one in Task B, the user enters the plaintext and the keyword, and the program reports the ciphertext.

Example:
$ ./vigenere

Enter plaintext: Hello, World!
Enter keyword  : cake
Ciphertext     : Jevpq, Wyvnd!
*/
#include <iostream>
#include <string>
using namespace std;

string encryptVigenere(string plaintext, string keyword) {
    int size = plaintext.length();
    int shift = keyword.length();
    int shiftIteration = 0;
    string cipher;
    if (shift == 1) {
        shift = (int)toupper(keyword[0]);
        for (int i = 0; i < size; i++) {
            if ((plaintext[i] >= 'a') && (plaintext[i] <= 'z')) {
                cipher += ((int)(plaintext[i] - 97) + ((int)keyword[0] - 65)) + 97;
            }
            else if ((plaintext[i] >= 'A') && (plaintext[i] <= 'Z')) {
                cipher += toupper(((int)plaintext[i] - 65) + ((int)keyword[0] - 65)  + 65);
            }

            else {
                cipher += plaintext[i];
            }
        }
    }
    else {
        for (int i = 0; i < size; i++) {
            if ((plaintext[i] >= 'a') && (plaintext[i] <= 'z')) {
                cipher += ((int)(plaintext[i] - 97) + ((int)keyword[(shiftIteration % shift)] - 97) % 24) + 97;
                shiftIteration++;
            }
            else if ((plaintext[i] >= 'A') && (plaintext[i] <= 'Z')) {
                cipher += toupper(((int)plaintext[i] - 65) + ((int)keyword[(shiftIteration % shift)] - 65) + 65);
                shiftIteration++;
            }

            else {
                cipher += plaintext[i];
            }
        }
    }

   
    return cipher;
}

int main(){
    cout << encryptVigenere("Hello, World!", "cake");

}

