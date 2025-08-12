#include "../include/WhatsApp.h"
#include <iostream>


using namespace std;

WhatsApp::WhatsApp() : currentUserIndex(-1) {}

WhatsApp::~WhatsApp() {
    for (auto* c : chats) delete c;
}

int WhatsApp::findUserIndex(string username) const {
    for (int i = 0; i < (int)users.size(); ++i)
        if (users[i].getUsername() == username) return i;
    return -1;
}

bool WhatsApp::isLoggedIn() const {
    return currentUserIndex != -1;
}

string WhatsApp::getCurrentUsername() const {
    if (!isLoggedIn()) return "";
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

    cout << "Password: ";  cin >> pwd;
    cout << "Phone: ";     cin >> phone;
    users.push_back(User(uname, pwd, phone));
    cout << "Account created! You can now log in.\n";
}

void WhatsApp::login() {
    if (isLoggedIn()) {
        cout << "You are already logged in as " << getCurrentUsername() << ".\n";
        return;
    }

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
    if (!isLoggedIn()) { cout << "You must log in first.\n"; return; }

    string otherUser;
    cout << "Enter username to chat with: ";
    cin >> otherUser;

    if (findUserIndex(otherUser) == -1) {
        cout << "No such user exists.\n";
        return;
    }

    auto* pc = new PrivateChat(getCurrentUsername(), otherUser);
    cout << "Private chat started between " << getCurrentUsername()
         << " and " << otherUser << ".\n";

    cout << "Type a message: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear leftover newline
    string msg; getline(cin, msg);

    pc->addMessage(Message(getCurrentUsername(), msg));

    cout << "\nChat History:\n";
    pc->displayChat();

    chats.push_back(pc); // persist
}

void WhatsApp::createGroup() {
    string groupName;
    cout << "Enter group name: ";
    getline(cin, groupName);

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    vector<string> members;
    members.push_back(getCurrentUsername());
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    int memberCount;
    cout << "How many members to add (excluding you)? ";
    while (!(cin >> memberCount) || memberCount < 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter a valid number: ";
    }

    for (int i = 0; i < memberCount; ++i) {
        string uname;
        cout << "Enter username " << (i + 1) << ": ";
        getline(cin, uname);

        if (findUserIndex(uname) != -1) {
            members.push_back(uname);
        } else {
            cout << "User " << uname << " not found. Skipped.\n";
        }
    }

  
    GroupChat* gc = new GroupChat(members, groupName, getCurrentUsername());
    chats.push_back(gc);

    cout << "Group '" << groupName << "' created.\n";
    gc->displayChat();


    cout << "Do you want to add extra admins now? (y/n): ";
    string yn;
    getline(cin, yn);
    if (!yn.empty() && (yn[0] == 'y' || yn[0] == 'Y')) {
        int adminCount;
        cout << "How many admins to add (besides you)? ";
        while (!(cin >> adminCount) || adminCount < 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter a valid number: ";
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int i = 0; i < adminCount; ++i) {
            string adminName;
            cout << "Enter admin username " << (i + 1) << ": ";
            getline(cin, adminName);

            
            if (gc->isParticipant(adminName)) {
                gc->addAdmin(adminName);
            } else {
                cout << adminName << " is not in the group. Skipped.\n";
            }
        }
        cout << "Updated group info:\n";
        gc->displayChat();
    }

   
    cout << "Send a first group message? (y/n): ";
    getline(cin, yn);
    if (!yn.empty() && (yn[0] == 'y' || yn[0] == 'Y')) {
        cout << "Type your message: ";
        string text;
        getline(cin, text);
        gc->addMessage(Message(getCurrentUsername(), text));
        cout << "\nMessage sent. Updated chat:\n";
        gc->displayChat();
    }
}



void WhatsApp::viewChats() const {
    cout << "\n=== Your Chats ===\n";
    if (chats.empty()) {
        cout << "You have no chats yet.\n";
        return;
    }
    for (size_t i = 0; i < chats.size(); ++i) {
        cout << "\n--- Chat #" << (i + 1) << " ---\n";
        chats[i]->displayChat();  
    }
}

void WhatsApp::logout() {
    if (!isLoggedIn()) { cout << "You are not logged in.\n"; return; }
    users[currentUserIndex].updateLastSeen();
    users[currentUserIndex].setStatus("Offline");
    cout << "Logged out.\n";
    currentUserIndex = -1;
}

void WhatsApp::run() {
    while (true) {
        if (!isLoggedIn()) {
            cout << "\n1. Login\n2. Sign Up\n3. Exit\nChoice: ";
            int choice;
            if (!(cin >> choice)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid.\n";
                continue;
            }
            if (choice == 1)      login();
            else if (choice == 2) signUp();
            else if (choice == 3) break;
            else                  cout << "Invalid.\n";
        } else {
            cout << "\n1. Start Private Chat\n2. Create Group\n3. View Chats\n4. Logout\nChoice: ";
            int choice;
            if (!(cin >> choice)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid.\n";
                continue;
            }
            if      (choice == 1) startPrivateChat();
            else if (choice == 2) createGroup();
            else if (choice == 3) viewChats();
            else if (choice == 4) logout();
            else                  cout << "Invalid.\n";
        }
    }
}
