#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include "User.h"

using namespace std;

class Message {
private:
    string sender;
    string content;
    string timestamp;
    string status;
    Message* replyTo;

public:
    Message();
    Message(string sndr, string cntnt);

    string getContent() const;
    string getSender() const;
    string getTimestamp() const;
    string getStatus() const;
    Message* getReplyTo() const;

    void setStatus(string newStatus);
    void setReplyTo(Message* msg);
    void updateTimestamp();
    void display() const;
    void addEmoji(string emojiCode);
};

#endif
