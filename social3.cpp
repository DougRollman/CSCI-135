


#include <iostream>
#include <string>
using namespace std;


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
    int numUsers;
    Profile profiles[MAX_USERS];
    bool following[MAX_USERS][MAX_USERS];    // new
    
public:
    Network() {
        numUsers = 0;
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

    // make them follow each other
    nw.follow("mario", "luigi");
    nw.follow("mario", "yoshi");
    nw.follow("luigi", "mario");
    nw.follow("luigi", "yoshi");
    nw.follow("yoshi", "mario");
    nw.follow("yoshi", "luigi");

    // add a user who does not follow others
    nw.addUser("wario", "Wario");

    // add clone users who follow @mario
    for (int i = 2; i < 6; i++) {
        string usrn = "mario" + to_string(i);
        string dspn = "Mario " + to_string(i);
        nw.addUser(usrn, dspn);
        nw.follow(usrn, "mario");
    }
    // additionally, make @mario2 follow @luigi
    nw.follow("mario2", "luigi");

    nw.printDot();
}