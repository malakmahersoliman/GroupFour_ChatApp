#include "../include/Chat.h"
#include "../include/Message.h"
#include <fstream>
#include <iostream>

using namespace std;

Chat::Chat() : chatName("Unnamed Chat") {}

Chat::Chat(vector<string> users, string name)
    : participants(users), chatName(name) {}

void Chat::addMessage(const Message& msg) {
    messages.push_back(msg);
}

bool Chat::deleteMessage(int index, const string& username) {
    if (index >= 0 && index < (int)messages.size() &&
        messages[index].getSender() == username) {
        messages.erase(messages.begin() + index);
        return true;
    }
    return false;
}

void Chat::displayChat() const {
    // keep it minimal so vtable gets emitted
    cout << "Chat: " << chatName << "\n";
    for (const auto& m : messages) m.display();
}

vector<Message> Chat::searchMessages(string keyword) const {
    vector<Message> out;
    for (const auto& m : messages) {
        if (m.getContent().find(keyword) != string::npos) out.push_back(m);
    }
    return out;
}

void Chat::exportToFile(const string& filename) const {
    ofstream f(filename);
    if (!f.is_open()) return;
    for (const auto& m : messages) {
        f << "[" << m.getTimestamp() << "] "
          << m.getSender() << ": "
          << m.getContent()
          << " [" << m.getStatus() << "]\n";
    }
}
