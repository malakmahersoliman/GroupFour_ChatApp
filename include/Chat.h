#ifndef CHAT_H
#define CHAT_H

#include <string>
#include <vector>
#include "Message.h"

using namespace std;

class Chat {
protected:
    vector<string> participants;
    vector<Message> messages;
    string chatName;

public:
    Chat();
    Chat(vector<string> users, string name);

    void addMessage(const Message& msg);
    bool deleteMessage(int index, const string& username);
    virtual void displayChat() const;
    vector<Message> searchMessages(string keyword) const;
    void exportToFile(const string& filename) const;
};

#endif
