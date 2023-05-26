#include <iostream>
#include <string>
using namespace std;

// new struct for lab 11d
struct Post {
    string username;
    string message;
};

//got the idea for the function from stack overflow. Changed it to meet my needs/ return a bool/ take arguments
bool isAlphanumeric(string str) {
    // initializing int type variables to 
    // perform operations
    int i, check = 0;

    // for loop to traverse the whole string
    for (i = 0; i < str.length(); i++) {
        // if condition to check for alphabet and 
        // numericals in the string
        if ((str[i] >= 'A' && str[i] <= 'Z') ||
            (str[i] >= 'a' && str[i] <= 'z') ||
            (str[i] >= '0' && str[i] <= '9')) {
            check++;
        }
        else {
            check = 0;
            break;
        }
    }

    if (check != 0) {
        return true;
    }
    else {
        return false;
    }
}

class Profile {
private:
    string username;
    string displayname;
public:
    // Profile constructor for a user (initializing 
    // private variables username=usrn, displayname=dspn)
    Profile(string usrn, string dspn) {
        username = usrn;
        displayname = dspn;
    }
    // Default Profile constructor (username="", displayname="")
    Profile() {
        username = "";
        displayname = "";
    }
    // Return username
    string getUsername() {
        return username;
    }
    // Return name in the format: "displayname (@username)"
    string getFullName() {
        string fullName;
        fullName = displayname + " (@" + username + ")";

        return fullName;
    }
    string getDisplayName() {
        return displayname;
    }
    // Change display name
    void setDisplayName(string dspn) {
        displayname = dspn;
    }
};

class Network {
private:
    static const int MAX_USERS = 20;
    static const int MAX_POSTS = 100;
    int numPosts, numUsers;                 // number of posts
    Post posts[MAX_POSTS];           // array of all posts
    Profile profiles[MAX_USERS];
    bool following[MAX_USERS][MAX_USERS];    // new for lab 11c

public:
    Network() {
        numUsers = 0;
        numPosts = 0;
    }
    // Add a new post
    bool writePost(string usrn, string msg)
    {
        if (numPosts == MAX_POSTS)
        {
            return false;
        }
        else
        {
            posts[numPosts].username = usrn;
            posts[numPosts].message = msg;
            numPosts++;
            return true;
        }
    }
    // Print user's "timeline"
    bool printTimeline(string usrn)
    {
        int iDPOS = findID(usrn);

        for (int i = (MAX_POSTS-1); i >= 0; i--)
        {
            if (posts[i].username == usrn || following[iDPOS][findID(posts[i].username)] == true)
            {
                Profile userProfile = profiles[findID(posts[i].username)];
                cout << userProfile.getFullName() << ": " << posts[i].message << endl;
            }
        }
        return true;
    }
    int findID(string usrn) {
        int userId = -1;
        for (int i = 0; i < numUsers; i++) {
            if (usrn == profiles[i].getUsername()) {
                userId = i;
            }
        }
        return userId;
    }
    bool addUser(string usrn, string dspn) {
        if (numUsers == MAX_USERS) {
            return false;
        }
        if (!isAlphanumeric(usrn)) {
            return false;
        }
        for (int i = 0; i < numUsers; i++) {
            if ((profiles[i].getUsername() == usrn) || (profiles[i].getDisplayName() == dspn)) {
                return false;
            }
        }

        profiles[numUsers] = Profile(usrn, dspn);
        numUsers++;
        if (profiles[numUsers - 1].getUsername() == usrn) {
            return true;
        }
        else {
            return false;
        }


    }
    // Make 'usrn1' follow 'usrn2' (if both usernames are in the network).
// return true if success (if both usernames exist), otherwise return false
    bool follow(string usrn1, string usrn2)//new
    {
        if (findID(usrn1) == -1)
            return false;
        else
        {
            for (int i = 0; i < numUsers; i++)
                if (profiles[i].getUsername() == usrn2)
                {
                    following[findID(usrn1)][i] = true;
                    return true;
                }
        }
        return false;
    }
    void printDot()                         // new
    {
        cout << "digraph { " << endl;
        for (int i = 0; i < numUsers; i++)
        {
            cout << "  \"@" << profiles[i].getUsername() << "\"" << endl;
        }
        cout << endl;
        for (int i = 0; i < numUsers; i++)
        {
            for (int j = 0; j < numUsers; j++)
            {
                if (following[i][j] == true)
                    cout << "  \"@" << profiles[i].getUsername() << "\"" " -> " << "\"@" << profiles[j].getUsername() << "\"" << endl;
            }
        }
        cout << "}" << endl;
    }

};


int main() {
    Network nw;
    // add three users
    nw.addUser("mario", "Mario");
    nw.addUser("luigi", "Luigi");
    nw.addUser("yoshi", "Yoshi");

    nw.follow("mario", "luigi");
    nw.follow("luigi", "mario");
    nw.follow("luigi", "yoshi");
    nw.follow("yoshi", "mario");

    // write some posts
    nw.writePost("mario", "It's a-me, Mario!");
    nw.writePost("luigi", "Hey hey!");
    nw.writePost("mario", "Hi Luigi!");
    nw.writePost("yoshi", "Test 1");
    nw.writePost("yoshi", "Test 2");
    nw.writePost("luigi", "I just hope this crazy plan of yours works!");
    nw.writePost("mario", "My crazy plans always work!");
    nw.writePost("yoshi", "Test 3");
    nw.writePost("yoshi", "Test 4");
    nw.writePost("yoshi", "Test 5");

    cout << endl;
    cout << "======= Mario's timeline =======" << endl;
    nw.printTimeline("mario");
    cout << endl;

    cout << "======= Yoshi's timeline =======" << endl;
    nw.printTimeline("yoshi");
    cout << endl;
}