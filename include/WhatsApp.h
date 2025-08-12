#ifndef WHATSAPP_H
#define WHATSAPP_H

#include <vector>
#include <string>
#include "User.h"
#include "Chat.h"
#include "PrivateChat.h"
#include "GroupChat.h"

using namespace std;

class WhatsApp {
private:
    vector<User> users;
    vector<Chat*> chats;   
    int currentUserIndex;

    int findUserIndex(string username) const;
    bool isLoggedIn() const;
    string getCurrentUsername() const;

public:
    WhatsApp();
    ~WhatsApp();                

    void signUp();
    void login();
    void startPrivateChat();
    void createGroup();
    void viewChats() const;
    void logout();
    void run();
};

#endif
