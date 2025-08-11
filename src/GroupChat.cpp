#include "../include/GroupChat.h"
#include <iostream>

using namespace std;

// ========================
//      GROUP CHAT CLASS
// ========================
// part 1 ##############################
GroupChat::GroupChat(vector<string> users, string name, string creator) {
    // TODO: Implement constructor
    participants = users;
    chatName = name;
    admins.push_back(creator);
    description = "New group created by " + creator;
}
// part 2 ##############################
void GroupChat::addAdmin(string newAdmin) {
    // TODO: Implement add admin
    for (int i = 0; i < admins.size(); i++) {
        if (admins[i] == newAdmin) return;
    }
    admins.push_back(newAdmin);
}
// part 3 ##############################
bool GroupChat::removeParticipant(const string& admin, const string& userToRemove) {
    // TODO: Implement remove participant
    /*check if admin or not 
    if not admin >> only admin can remove */
    bool is_admin = false;
    for (string a : admins) {
        if (a == admin) {
            is_admin = true;
            break;
        }
    }
    if (!is_admin) {
        cout << "Only admins can remove members!\n";
        return false;
    }

	// Check if the user to remove is a participant and if remove 
    bool removed = false;
    int i = 0;
    while (i < participants.size()) {
        if (participants[i] == userToRemove) {
            participants.erase(participants.begin() + i);
            removed = true;
        }
        else {
            i++;
        }
    }
	// If the user was removed, also remove from admins if they are an admin
    if (removed) {
        int j = 0;
        while (j < admins.size()) {
            if (admins[j] == userToRemove) {
                admins.erase(admins.begin() + j);
            }
            else {
                j++;
            }
        }
        cout << "Removed " << userToRemove << " from group.\n";
        return true;
    }
    cout << "User not found in group.\n";
    return false;

}
// part 4 ##############################
bool GroupChat::isAdmin(string username) const {
    // TODO: Implement admin check'
    for (string admin : admins){
        if (admin == username) {
            return true;
        }
    }
    return false;
}
// part 5 ##############################
bool GroupChat::isParticipant(string username) const {
    // TODO: Implement participant check
    for (string member : participants) {
        if (member == username) {
            return true;
        }
    }
    return false;
}
//  part 6 ##############################
void GroupChat::setDescription(string desc) {
    // TODO: Implement set description
    description = desc;  // Update description
    cout << "Group description updated to: " << desc << "\n";
}
// part 7 ##############################
void GroupChat::displayChat() const {
    // TODO: Implement group chat display
    
         // Header
     cout << "\n══════════════════════════════\n";
     cout << "  GROUP: " << chatName << "\n";
     cout << "  Description: " << description << "\n\n";

     // Admin List
    cout << "  Admins (" << admins.size() << "):\n";
    for (const string& admin : admins) {
        cout << "  - " << admin << "\n";
    }

    // Participant List
    cout << "\n  Members (" << participants.size() << "):\n";
    for (const string& member : participants) {
        cout << "  - " << member;
        if (isAdmin(member)) cout << " (Admin)";
        cout << "\n";
    }

    // Message History
    cout << "\n  Messages (" << messages.size() << "):\n";
    if (messages.empty()) {
        cout << "  No messages yet.\n";
    }
    else {
        for (const Message& msg : messages) {
            cout << "  [" << msg.getTimestamp() << "] "
                << msg.getSender() << ": "
                << msg.getContent() << "\n";
        }
    }
    cout << "══════════════════════════════\n";
}


// part 8 ##############################
void GroupChat::sendJoinRequest(const string& username) {
    // TODO: Implement join request
    cout << username << " has requested to join the group.\n";
}
