#include "../include/WhatsApp.h"
#include <iostream>

using namespace std;

WhatsApp::WhatsApp() : currentUserIndex(-1) {}

int WhatsApp::findUserIndex(string username) const {
    for (int i = 0; i < users.size(); ++i) {
        if (users[i].getUsername() == username) return i;
    }
    return -1;
}

bool WhatsApp::isLoggedIn() const {
    return currentUserIndex != -1;
}

string WhatsApp::getCurrentUsername() const {
    return users[currentUserIndex].getUsername();
}

void WhatsApp::signUp() {
    string uname, pwd, phone;
    cout << "\n=== Sign Up ===\n";
    cout << "Username: ";  cin >> uname;

    if (findUserIndex(uname) != -1) {
        cout << "Username already taken. Try another.\n";
        return;
    }
    cout << "Password:";  cin >> pwd;
    cout << "Phone:";  cin >> phone;
    users.push_back(User(uname, pwd, phone));
    cout << "Account created! You can now log in.\n";
}

void WhatsApp::login() {
    string uname, pwd;
    cout << "\n=== Login ===\n";
    cout << "Username: "; cin >> uname;
    cout << "Password: "; cin >> pwd;

    int idx = findUserIndex(uname);
    if (idx == -1) {
        cout << "No such user.\n";
        return;
    }
    if (!users[idx].checkPassword(pwd)) {
        cout << "Wrong password.\n";
        return;
    }
    currentUserIndex = idx;
    users[idx].setStatus("Online");
    cout << "Logged in. Welcome, " << uname << "!\n";
}

void WhatsApp::startPrivateChat() {
    cout << "(will be implemented later)\n";
}

void WhatsApp::createGroup() {
    cout << "(will be implemented later)\n";
}

void WhatsApp::viewChats() const {
    cout << "(will be implemented later)\n";
}

void WhatsApp::logout() {
    users[currentUserIndex].updateLastSeen();
    //cout << "Last seen updated to: " << users[currentUserIndex].getLastSeen() << endl;
    users[currentUserIndex].setStatus("Offline");
    
    cout << "Logged out.\n";
    currentUserIndex = -1;
}

void WhatsApp::run() {
    while (true) {
        if (!isLoggedIn()) {
            cout << "\n1. Login\n2. Sign Up\n3. Exit\nChoice: ";
            int choice;
            cin >> choice;

            if (choice == 1) login();
            else if (choice == 2) signUp();
            else if (choice == 3) break;
            else cout << "Invalid.\n";
        }
        else {
            cout << "\n1. Start Private Chat\n2. Create Group\n3. View Chats\n4. Logout\nChoice: ";
            int choice;
            cin >> choice;

            if (choice == 1) startPrivateChat();
            else if (choice == 2) createGroup();
            else if (choice == 3) viewChats();
            else if (choice == 4) logout();
            else cout << "Invalid.\n";
        }
    }
}
