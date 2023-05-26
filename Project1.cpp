//Douglas Rollaan
/*
CS 135
2/9/23
*/


/*

Assignment: Project 1 
Part B
--------------------------------
Now that we have the words stored, it is time to provide functions that allow users to use our dictionary. Add and implement the following functions:


    @param            :   The string with a query word
    @return           :   Integer index of the word in
                          `g_words` global-array. Returns
                          -1 if the word is not found
    @post             :   Find the index of given `word`
                          in the `g_words` array. Return -1
                          if word is not in the array

int getIndex(string word);


    @param            :   The string with a query word
    @return           :   Return the string definition of
                          the word from  `g_definitions`
                          global-array. Return "NOT_FOUND" if
                          word doesn't exist in the dictionary
    @post             :   Find the definition of the given `word`
                          Return "NOT_FOUND" otherwise

string getDefinition(string word);


    @param            :   The string with a query word
    @return           :   Return the string part-of-speech(pos)
                          from the `g_pos` global-array. Return
                          "NOT_FOUND" if the word doesn't exist
                          in the dictionary.
    @post             :   Find the pos of the given `word`
                          Return "NOT_FOUND" otherwise

string getPOS(string word);


    @param            :   The string prefix of a word (the prefix
                          can be of any length)
    @return           :   Integer number of words found that starts
                          with the given `prefix`
    @post             :   Count the words that start with the given
                          `prefix`

int countPrefix(string prefix);
Remember to test each function before moving on to implement the next one.Similar to Task A, submit only one.cpp file without the main() function.

*/

#include <iostream>
#include <cstdlib>
#include <climits>
#include <fstream>
#include <string>
#include <stdlib.h>

using std::cout;
using std::cin;
using std::endl;
using std::cerr;
using std::string;
using std::ifstream;


const int g_MAX_WORDS = 1000;
int g_word_count = 0;

string g_words[g_MAX_WORDS];
string g_definitions[g_MAX_WORDS];
string g_pos[g_MAX_WORDS];



string getRandomWord() {
    srand((unsigned)time(NULL));
    int index = rand() % g_word_count;
    return g_words[index];
}

/*
    @param            :   The string with a query word
    @return           :   Integer index of the word in
                          `g_words` global-array. Returns
                          -1 if the word is not found
    @post             :   Find the index of given `word`
                          in the `g_words` array. Return -1
                          if word is not in the array

*/

int getIndex(string word) {
    for (int i = 0; i < g_word_count; i++) {
        if (g_words[i] == word) {
            return i;
        }
    }
    return -1;
}

/*
@param            :   The string with a query word
@return           :   Return the string definition of
the word from  `g_definitions`
global - array.Return "NOT_FOUND" if
word doesn't exist in the dictionary
@post             :   Find the definition of the given `word`
Return "NOT_FOUND" otherwise
*/

string getDefinition(string word) {
    int pos = getIndex(word);
    if (g_words[pos] == word) {
        pos = getIndex(word);
        return g_definitions[pos];
    }
    else {
        return "NOT_FOUND";
    }
}
/*
@param            :   The string with a query word
@return           :   Return the string part - of - speech(pos)
from the `g_pos` global - array.Return
"NOT_FOUND" if the word doesn't exist
in the dictionary.
@post             :   Find the pos of the given `word`
Return "NOT_FOUND" otherwise
*/

string getPOS(string word) {
    {
        int pos = getIndex(word);
        if (g_words[pos] == word) {
            return g_pos[pos];
        }
        else {
            return "NOT_FOUND";
        }
    }
}

/*
    @param            :   The string prefix of a word (the prefix
                          can be of any length)
    @return           :   Integer number of words found that starts
                          with the given `prefix`
    @post             :   Count the words that start with the given
                          `prefix`
*/

int countPrefix(string prefix) {
    int len = prefix.length();
    int prefcount = 0;
    for (int i = 0; i < g_word_count; i++) {
        if (prefix == g_words[i].substr(0, len)) {
            prefcount += 1;
        }
    }
    return prefcount;
}


/*
@param : The string with the `filename`
@post             :   Reads the words, definitions
pos into the global - arrays
and set the value of `g_word_count`
to the number of words read
*/



void readWords(string filename) {
    ifstream fin(filename);
    
    int pos1;
    int pos2;
    int pos3;
    int i = 0;
    if (fin.fail()) {
        cerr << "File cannot be opened for reading." << endl;
        exit(1); // exit if failed to open the file
    }

    string line, junk;        // new string variable
    while (getline(fin, line)) {

        g_word_count += 1;
        pos1 = line.find(":");
        g_definitions[i] = line.substr(pos1 + 2);
        pos2 = line.find(" ");
        g_words[i] = line.substr(0, pos2);
        junk = line.substr(pos2 + 1);
        pos3 = junk.find(" ");
        g_pos[i] = junk.substr(0, pos3);
        i++;
    }


}
/*
    @param word       :   The string with a new word
    @param definition :   The string with the definition of the
                          new `word`
    @param pos        :   The string with the pos of the new `word`
    @return           :   return `true` if the word is
                          successfully added to the dictionary
                          return `false` if failed (word already
                          exists or dictionary is full)
    @post             :   Add the given `word`, `definition`, `pos`
                          to the end of the respective
                          global-arrays.
                          The word should not be added to the
                          global-arrays if it already exists
                          or if the array reached maximum
                          capacity(`g_MAX_WORDS`).
                          Update `g_word_count` if the word is
                          successfully added
*/
bool addWord(string word, string definition, string pos) {
    if (g_words[getIndex(word)] == word) {
        return false;
    }
    if (g_word_count == g_MAX_WORDS) {
        return false;
    }
    g_word_count++;
    g_words[g_word_count-1] = word;
    g_definitions[g_word_count-1] = definition;
    g_pos[g_word_count-1] = pos;
    return true;
}

/*
    @param word       :   The string with the word that is to
                          be edited
    @param definition :   The string with the new definition of
                          the `word`
    @param pos        :   The string with the new pos of the `word`
    @return           :   return `true` if the word is successfully
                          edited, return `false` if the `word`
                          doesn't exist in the dictionary
    @post             :   Replace the given `word`'s  definition
                          and pos with the given `definition` and
                          `pos` (by modifying global-arrays
                          `g_definitions` and `g_pos`).
                          The modification will fail if the word
                          doesn't exist in the dictionary
*/
bool editWord(string word, string definition, string pos) {
    int location = getIndex(word);
    g_words[location] = word;
    g_definitions[location] = definition;
    g_pos[location] = pos;
    g_word_count++;
    if (getIndex(word)) {
        return true;
    }
    else {
        return false;
    }
}

/*
    @param            :   The string with the word that is to
                          be removed
    @return           :   return `true` if the word is successfully
                          removed from the dictionary return `false`
                          if the word doesn't exist in the dictionary
    @post             :   Remove the given `word`, `word`'s
                          definition and `word`'s pos from the
                          respective global-arrays if the word
                          exists.
                          Update `g_word_count` if the word is
                          successfully removed
*/
bool removeWord(string word) {
    if (g_words[getIndex(word)] == word) {
        int location = getIndex(word);
        for (int i = location; i <= g_word_count; i++) {
            g_words[i] = g_words[i + 1];
            g_pos[i] = g_pos[i + 1];
            g_definitions[i] = g_definitions[i + 1];
        }
        g_word_count--;
        return true;
    }
    else {
        return false;
    }
}
    



/*
    @param            :   The string with a word from the dictionary
    @return           :   string of "_" based on the number of
                          characters in the given `word`
    @post             :   Return string of "_" based on the length
                          of the given `word`.
                          For example, if the word is "game", then
                          the function would return "____". In other
                          words, a string of four "_"s.
*/
string maskWord(string word) {
    string mask = "";
    int size = word.length();
    for (int i = 0; i < size; i++) {
        mask += "_";
    }
    return mask;
}
/*
    @param            :   The integer for the difficulty of the game
                          (0 for easy, 1 for normal, and 2 for hard)
    @return           :   The number of tries given the `difficulty`
                          (9 for easy, 7 for normal, and 5 for hard)
    @post             :   Return the number of tries based on given
                          difficulty (0-easy: 9 tries, 1-normal: 7
                          tries, 2-Hard: 5 tries)
*/
int getTries(int difficulty) {
    int easy = 9;
    int normal = 7;
    int hard = 5;
    if ((difficulty < 0) || (difficulty > 2)) {
        return -1;
    }
    if (difficulty == 0) {
        return easy;
    }
    if (difficulty == 1) {
        return normal;
    }
    if (difficulty == 2) {
        return hard;
    }
}



/*
    @param tries      :   The integer for remaining tries
    @param difficulty :   The integer for the difficulty of the game
                          (0 for easy, 1 for normal, and 2 for hard)
    @post             :   prints the number of lives left and number
                          of lives used using "O" and "X". DO NOT
                          PRINT AN ENDLINE

    For example : calling `printAttemps(2, 1)` would print "OOXXXXX".
                  Based on given `difficulty`, we know the total tries
                  is 7 (from `getTries(1)`). Also, the player has 2
                  `tries` remaining based on the given parameter.
                  Therefore, the function prints two "O"s to indicate
                  the remaining tries and 5 "X"s to indicate the tries
                  that have been used (7-2=5)
*/
void printAttempts(int tries, int difficulty) {
    
    int size;
    if (difficulty == 0) {
        size = 9;
    }
    else if (difficulty == 1) {
        size = 7;
    }
    else {
        size = 5;
    }
    for (int i = 0; i < size; i++) {
        if (i < tries) {
            cout << "O";
        }
        else {
            cout << "X";
        }
    }
}

/*
    @param word       :   The string word from the dictionary
    @param letter     :   The char letter that that will be revealed
    @param(&) current :   The string representing a masked word
    @return           :   `true` if the `letter` exists in `word`,
                          otherwise return `false`
    @post             :   If the given `letter` exists in `word`
                          reveal the `letter` in `current` masked word
                          and return `true`. Otherwise, return `false`

    For example : Let's say we have the following main function:
                  int main(){
                      string w = "g___";
                      cout << revealLetter("good", 'o', "g___") << endl;
                      cout <<  w << endl;
                  }
                  The first `cout` will print 1 because the letter 'o'
                  exists in "good". Thus, the function returned `true`.
                  The second `cout` will print "goo_". The variable `w`
                  has been modified by the function to reveal all the
                  `o`s in "good" resulting in "goo_"
*/
bool revealLetter(string word, char letter, string& current) {
    int size = word.length();
    bool flag = false;
    for (int i = 0; i < size; i++) {
        if (word[i] == letter) {
            current[i] = letter;
            flag = true;
        }
    }
    return flag;
}

int main()
{
    string a = "hello";
    maskWord(a);
    return 0;
}

