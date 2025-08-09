#include "../include/GroupChat.h"


using namespace std;

// ========================
//      GROUP CHAT CLASS
// ========================

GroupChat::GroupChat(vector<string> users, string name, string creator) {
    // TODO: Implement constructor
}

void GroupChat::addAdmin(string newAdmin) {
    // TODO: Implement add admin
}

bool GroupChat::removeParticipant(const string& admin, const string& userToRemove) {
    // TODO: Implement remove participant
    return false;
}

bool GroupChat::isAdmin(string username) const {
    // TODO: Implement admin check
    return false;
}

bool GroupChat::isParticipant(string username) const {
    // TODO: Implement participant check
    return false;
}

void GroupChat::setDescription(string desc) {
    // TODO: Implement set description
}

void GroupChat::displayChat() const {
    // TODO: Implement group chat display
}

void GroupChat::sendJoinRequest(const string& username) {
    // TODO: Implement join request
}
