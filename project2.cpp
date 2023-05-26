/*
Douglas Rollaan
CS 135
Project 2A
*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;


//global variables for
int g_curr_size = 2;
int g_number_of_songs = 0;


string* g_song_names = new string[g_curr_size];
string* g_artist_names = new string[g_curr_size];
int* g_song_durations = new int[g_curr_size];
string* g_genres = new string[g_curr_size];

/*
    @post             :   Replace the old global
                          dynamically allocated arrays
                          with new dynamically allocated
                          arrays of twice the size
                          ('g_curr_size' * 2). Update
                          'g_curr_size' accordingly.
                          Make sure you copy the contents
                          of the older arrays. Do this
                          for the following global-arrays:
                          'g_song_names', 'g_artist_names',
                          'g_song_durations', 'g_genres'
*/
void allocateNew() {
    string* bigger_g_song_names = new string[2 * g_curr_size];
    string* bigger_g_artist_names = new string[2 * g_curr_size];
    int* bigger_g_song_durations = new int[2 * g_curr_size];
    string* bigger_g_genres = new string[2 * g_curr_size];
    for (int i = 0; i < g_curr_size; i++) {
        bigger_g_song_names[i] = g_song_names[i];
        bigger_g_artist_names[i] = g_artist_names[i];
        bigger_g_song_durations[i] = g_song_durations[i];
        bigger_g_genres[i] = g_genres[i];
    }
    delete[] g_song_names;  
    delete[] g_artist_names;
    delete[] g_song_durations;
    delete[] g_genres;

    g_song_names = bigger_g_song_names;
    g_artist_names = bigger_g_artist_names;
    g_song_durations = bigger_g_song_durations;
    g_genres = bigger_g_genres;
    g_curr_size = 2 * g_curr_size;
    bigger_g_artist_names = nullptr;
    bigger_g_genres = nullptr;
    bigger_g_song_durations = nullptr;
    bigger_g_song_names = nullptr;

}   
/*
    @param            :   The string with the 'filename'
    @post             :   Reads the song, artists,
                          song durations and genres into
                          the global-arrays and set the
                          value of 'g_number_of_songs'
                          to the number of songs read.
                          Call 'allocateNew()' to allocate
                          an array of larger size if the
                          dynamic arrays reach full
                          capacity.
*/

void readSongs(string filename) {
    ifstream fin(filename);

    int pos1;
    int pos2;
    int pos3;
    int pos4;
    int i = 0;
    if (fin.fail()) {
        cerr << "File cannot be opened for reading." << endl;
        exit(1); // exit if failed to open the file
    }

    string line, junk;        // new string variable
    while (getline(fin, line)) {
        if (g_number_of_songs == g_curr_size) {
            allocateNew();
        }
        g_number_of_songs++;
        pos1 = line.find(":");
        g_song_names[i] = line.substr(0, pos1);
        line = line.substr(pos1 + 1);
        pos2 = line.find("-");
        g_artist_names[i] = line.substr(0, pos2);
        line = line.substr(pos2 + 1);
        pos3 = line.find("-");
        g_genres[i] = line.substr(0, pos3);
        line = line.substr(pos3+1);
        pos4 = line.find(' ');
        line = line.substr(0, pos4);
        g_song_durations[i] = stoi(line);
        i++;
    }
}

int main() {
    readSongs("playlist.txt");
    for (int i = 0; i < g_number_of_songs; i++) {
        cout << g_song_durations[i] << endl;
    }
}