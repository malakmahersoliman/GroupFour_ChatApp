#ifndef WHATSAPP_H
#define WHATSAPP_H

#include <vector>
#include <string>
#include "User.h"
#include "Chat.h"
#include "PrivateChat.h"
#include "GroupChat.h"

class WhatsApp {
private:
    std::vector<User> users;
    std::vector<Chat*> chats;
    int currentUserIndex;

    int findUserIndex(std::string username) const;
    bool isLoggedIn() const;
    std::string getCurrentUsername() const;

public:
    WhatsApp();
    void signUp();
    void login();
    void startPrivateChat();
    void createGroup();
    void viewChats() const;
    void logout();
    void run();
};

#endif
