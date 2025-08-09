#ifndef PRIVATECHAT_H
#define PRIVATECHAT_H


#include "Chat.h"
#include "User.h"


using namespace std;

class PrivateChat : public Chat {
private:
    string user1;
    string user2;

public:
    PrivateChat(string u1, string u2);
    void displayChat() const override;
    void showTypingIndicator(const string& username) const;
};

#endif
