INDX( 	 ��N5.           (   8   �       U user(idi] e                       �'   b 4<�Dy��jv�Dy��jv�Dy��jv�Dy�                      s c . u s e r _ p a g e d . 1 . e t l               �'   b 4<�Dy��jv�Dy��jv�Dy��jv�Dy�                      S C U S E R ~ 2 . E T L                     �'   r p Z     �'   b 4<�Dy��jv�Dy��jv�Dy��jv�Dy�                      S C U S E R ~ 2 . E T L                     �'   b 4<�Dy��jv�Dy��jv�Dy��jv�Dy�                      S C  S E R ~ 2 . E T L                     �jv�Dy��jv�Dy��jv�Dy�                      S C U S E R ~ 2 . E T L                        check++;
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
    // private variables username= rn, displayname=dspn)
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
        fullName = displayname + " (@" + us name + ")";

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
    static const int MAX_USERS = 20; // max number of user profiles
    int numUsers;                    // number of registered users
    Profile profiles[MAX_USERS];     // user profiles array:
    // mapping integer ID -> Profile

// Returns user ID  ndex in the 'profiles' array) by their username
// (or -1 if username is not found)
    int findID(string usrn) {
        int userId = -1;
        for (int i = 0; i < numUsers; i++) {
            if (usrn == profiles[i].getUsername()) {
                userId = i;
            }
        }
        return userId;
    }
public:
    // Constructor, makes an empty network (numUsers = 0)
    Network() {
        numUsers = 0;
    }
    // Attempts to sign up a new user with specified username and  splayname
    // return true if the operation was successful, otherwise return false
    bool addUser(string usrn, string dspn) {
        if (numUsers == MAX_USERS) {
            return false;
        }
        if (!isAlphanumeric(usrn)) {
            return false;
        }
        for (int i = 0; i < numUsers; i++) {
            if ((profiles[i].getUsername() == usrn)||(profiles[i].getDisplayName() == dspn)){
                return false;
            }
        }

        profiles[numUsers = Profile(usrn, dspn);
        numUsers++;
        if (profiles[numUsers - 1].getUsername() == usrn) {
            return true;
        }
        else {
            return false;
        }


    }
};

int main() {
    Network nw;
    cout << nw.addUser("mario", "Mario") << endl;     // true (1)
    cout << nw.addUser("luigi", "Luigi") << endl;     // true (1)

    cout << nw.addUser("mario", "Mario2") << endl;    // false (0)
    cout << nw.addUser("mario 2", "Mario2") << endl;  // fals (0)
    cout << nw.addUser("mario-2", "Mario2") << endl;  // false (0)

    for (int i = 2; i < 20; i++)
        cout << nw.addUser("mario" + to_string(i),
            "Mario" + to_string(i)) << endl;   // true (1)

    cout << nw.addUser("yoshi", "Yoshi") << endl;     // false (0)
}