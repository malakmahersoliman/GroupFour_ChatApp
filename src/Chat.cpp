#include <iostream>


#include "../include/Chat.h"
#include "../include/Message.h"

using namespace std;

// ========================
//       CHAT CLASS (BASE)
// ========================
Chat::Chat() {
    // TODO: Implement default constructor
}

// Parameterized constructor
Chat::Chat(vector<string> users, string name) {
    // TODO: Implement parameterized constructor
}

void Chat::addMessage(const Message& msg) {
    // TODO: Implement message addition
}

bool Chat::deleteMessage(int index, const string& username) {
    // TODO: Implement message deletion
    return false;
}

void Chat::displayChat() const {
    // TODO: Implement chat display
}

vector<Message> Chat::searchMessages(string keyword) const {
    // TODO: Implement message search
    return {};
}

void Chat::exportToFile(const string& filename) const {
    // TODO: Implement export to file
}
