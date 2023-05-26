/*
Douglas Rollaan
CS 135
Project 2A
*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;



class Song
{
public:
    string name;
    string artist;
    int duration;
    string genre;

};

//global variables for
int g_capacity = 2;
int g_size = 0;

Song* g_songs = new Song[g_capacity];

/*
    @post             :   Replace the old global
                          dynamically allocated array
                          'g_songs' with new dynamically
                          allocated array of twice the
                          capacity ('g_capacity' * 2).
                          Update 'g_capacity' accordingly.
                          Make sure you copy the contents
                          of the old array to the new one.
*/






void allocateNew() {
    Song* bigger_g_songs = new Song[2 * g_capacity];
    for (int i = 0; i < g_size; i++) {
        bigger_g_songs[i] = g_songs[i];
    }
    delete[] g_songs;
    g_songs = bigger_g_songs;
    bigger_g_songs = nullptr;
    g_capacity = g_capacity * 2;
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
/*
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
        if (g_capacity == g_size) {
            allocateNew();
        }
        g_size++;
        pos1 = line.find(":");
        g_songs[i].name = line.substr(0, pos1);
        line = line.substr(pos1 + 1);
        pos2 = line.find("-");
        g_songs[i].artist = line.substr(0, pos2);
        line = line.substr(pos2 + 1);
        pos3 = line.find("-");
        g_songs[i].genre = line.substr(0, pos3);
        line = line.substr(pos3 + 1);
        pos4 = line.find(' ');
        line = line.substr(0, pos4);
        g_songs[i].duration = stoi(line);
        i++;
    }
}

/*
    @param genre              :   A string representing a genre
    @param(&) genreCount      :   An integer that will keep track of the number of songs
    @return                   :   A pointer to a dynamically allocated array of strings
    @post                     :   Return a pointer to a dynamically allocated array of strings
                                  containing the names of the songs of given 'genre' and
                                  update 'genreCount' to be the number of songs found.
                                  Return a pointer to an empty dynamically allocated array
                                  if no songs are found of the given 'genre'

    For example : Let's say we have the following 'g_song_names':
                  ["Killshot", "Takeover", "Spectre", "Ether", "No Title"]

                  Let's say we have the following 'g_genres':
                  ["HipHop", "HipHop", "EDM", "HipHop", "JPop"]

                  We try the following code with the above global-arrays:
                  int main(){
                    int count = 0;
                    string * genreSongs = getGenreSongs("HipHop", count);
                  }

                  In this case, 'genreSongs' will be pointing to the following:
                  ["Killshot", "Takeover", "Ether"]
                  The value of 'count' will be updated to 3 because there
                  are three "HipHop" songs on the playlist
*/
/*
Song* getGenreSongs(string genre, int& genreCount) {
    genreCount = 0;
    Song* genreSongs = new Song[g_size];
    for (int i = 0; i < g_size; i++) {
        if (g_songs[i].genre == genre) {
            genreSongs[genreCount].genre = g_songs[i].genre;
            genreCount++;
        }
    }

    return genreSongs;
}

/*
    @param duration             :   The integer duration of the songs
    @param(&) durationsCount    :   An integer that will keep track of the number of songs
    @param filter               :   An integer(0, 1 or 2) representing the comparision filter
                                    0 = greater-than, 1 = less-than, 2 = equal-to
    @return                     :   A pointer to a dynamically allocated array of strings
    @post                       :   Return a pointer to a dynamically allocated array of strings
                                    of songs that are either greater-than, less-than or equal-to
                                    the given 'duration' based on given 'filter'. Update parameter
                                    'durationsCount' with the number of songs found. Return a
                                    pointer to an empty dynamically allocated array if no songs
                                    are found with the given parameters

    For example : Let's say we have the following 'g_song_names':
                  ["Major Crimes", "Never Fade Away", "Circus Minimus", "4aem", "Reaktion"]

                  Let's say we have the following 'g_song_durations':
                  [3, 4, 3, 5, 2]

                  We try the following code with the above global-arrays:
                  int main(){
                    int greater = 0;
                    int less = 0;
                    int equal = 0;
                    string * longSongs = getSongsFromDuration(3, greater, 0);
                    string * shortSongs = getSongsFromDuration(3, less, 1);
                    string * mediumSongs = getSongsFromDuration(3, equal, 2);
                  }

                  After running the above code, 'longSongs' will be:
                  ["Never Fade Away", "4aem"]
                  The value of 'greater' will be 2 because there are two songs
                  greater than 3 mins duration

                  Similarly, 'shortSongs' will be:
                  ["Reaktion"]
                  The value of 'less' will be 1 because there is only one song
                  less than 3 mins duration

                  Finally, 'mediumSongs' will be:
                  ["Major Crimes", "Circus Minimus"]
                  The value of 'equal' will be 2 because there are 2 songs
                  equal to 3 mins duration
*/
/*
Song* getSongsFromDuration(int duration, int& durationsCount, int filter) {
    Song* durationSort = new Song[g_size];
    durationsCount = 0;
    /*
    @param filter               :   An integer(0, 1 or 2) representing the comparision filter
                                    0 = greater-than, 1 = less-than, 2 = equal-to
    */
/*
    if (filter == 0) {
        for (int i = 0; i < g_size; i++) {
            if (duration < g_songs[i].duration) {
                durationSort[durationsCount].name = g_songs[i].name;
                durationsCount++;
            }
        }
        return durationSort;
    }
    if (filter == 1) {
        for (int i = 0; i < g_size; i++) {
            if (duration > g_songs[i].duration) {
                durationSort[durationsCount].name = g_songs[i].name;
                durationsCount++;
            }
        }
        return durationSort;
    }
    if (filter == 2) {
        for (int i = 0; i < g_size; i++) {
            if (duration == g_songs[i].duration) {
                durationSort[durationsCount].name = g_songs[i].name;
                durationsCount++;
            }
        }
        return durationSort;
    }
    else {
        return durationSort;
    }
}
/*
    @param      :   An integer that will keep track of unique artists
    @return     :   A pointer to a dynamically allocated array of strings
    @post       :   Return a pointer to a dynamically allocated array of strings
                    containing the names of unique artists in 'g_artist_names'
                    and update 'uniqueCount' parameter to be the number of
                    unique artists found

    For example : Let's say we have the following 'g_artist_names':
                  ["Eminem", "Eminem", "Jay Z", "Jay Z", "Nas"]

                  We try the following code with this 'g_artist_names':
                  int main(){
                    int count = 0;
                    string * uniques = getUniqueArtists(count);
                  }

                  In this case, 'uniques' will be pointing to the following:
                  ["Eminem", "Jay Z", "Nas"]
                  The value of 'count' will be updated to 3 because there
                  are three unique artists on the playlist
*/
/*
Song* getUniqueArtists(int& uniqueCount) {
    Song* uniqueArtists = new Song[g_size];
    bool flag = false;


    for (int i = 0; i < g_size; i++) {
        if (i == 0) {
            uniqueArtists[i].artist = g_songs[i].artist;
            uniqueCount++;
        }
        for (int j = 0; j < uniqueCount; j++) {
            if (uniqueArtists[j].artist == g_songs[i].artist) {
                flag = true;
            }
        }
        if (!flag) {
            uniqueArtists[uniqueCount].artist = g_songs[i].artist;
            uniqueCount++;
        }
        flag = false;
    }
    return uniqueArtists;
}
/*
    @return     :   A string with the artist with most songs in playlist
    @post       :   Find the artist with the most songs in the playlist
                    If there are multiple such artists, return any one of them.
                    Return "NONE" if the playlist is empty

    For example : Let's say we have the following 'g_artist_names':
                  ["J. Cole", "J. Cole", "Kendrick", "Kendrick", "Kendrick"]
                  The favorite artist here is "Kendrick" because he has 3 songs
                  However, consider the following 'g_artist_names':
                  ["J. Cole", "J. Cole", "Kendrick", "Kendrick", "Drake"]
                  In this case, the favorite artist is either "J.Cole" or "Kendrick"
                  because both artists have 2 songs which is greater than any
                  other artists in the playlist
*/
/*
string getFavoriteArtist() {
    int count = 0;
    Song* uniques = getUniqueArtists(count);
    int* uniquesCount = new int[count];
    string favoriteArtist;
    int favoriteArtistTotal = 0;
    if (count == 0) {
        return "NONE";
    }
    // initializing uniquesCount array
    for (int i = 0; i < count; i++) {
        uniquesCount[i] = 0;
    }
    for (int i = 0; i < g_size; i++) {
        for (int j = 0; j < count; j++) {
            if (uniques[j].artist == g_songs[i].artist) {
                uniquesCount[j] = uniquesCount[j] + 1;
            }
        }
    }
    for (int i = 0; i < count; i++) {
        if (uniquesCount[i] > favoriteArtistTotal) {
            favoriteArtistTotal = uniquesCount[i];
            favoriteArtist = uniques[i].artist;
        }
    }
    return favoriteArtist;
}











/*
############################################################################################################################################
                                                         ----Main Function----
############################################################################################################################################
*/





int main() {

    
}