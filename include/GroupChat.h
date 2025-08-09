#ifndef GROUPCHAT_H
#define GROUPCHAT_H

#include "Chat.h"
#include <vector>
#include <string>

using namespace std;


class GroupChat : public Chat {
private:
    vector<string> admins;
    string description;

public:
    GroupChat(vector<string> users, string name, string creator);

    void addAdmin(string newAdmin);
    bool removeParticipant(const string& admin, const string& userToRemove);
    bool isAdmin(string username) const;
    bool isParticipant(string username) const;
    void setDescription(string desc);
    void displayChat() const override;
    void sendJoinRequest(const string& username);
};

#endif
