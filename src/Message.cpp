#include "../include/Message.h"
#include <iostream>
#include <ctime>

using namespace std;

static string nowCtimeTrimmed() {
    time_t t = time(nullptr);
    string s = ctime(&t);
    if (!s.empty() && s.back() == '\n') s.pop_back();
    return s;
}

Message::Message()
: sender(""), content(""), timestamp(nowCtimeTrimmed()),
  status("sent"), replyTo(nullptr) {}

Message::Message(string sndr, string cntnt)
: sender(sndr), content(cntnt),
  timestamp(nowCtimeTrimmed()), status("sent"),
  replyTo(nullptr) {}

string Message::getContent() const { return content; }
string Message::getSender()  const { return sender; }
string Message::getTimestamp() const { return timestamp; }
string Message::getStatus()  const { return status; }
Message* Message::getReplyTo() const { return replyTo; }

void Message::setStatus(string newStatus) { status = newStatus; }
void Message::setReplyTo(Message* msg) { replyTo = msg; }

void Message::updateTimestamp() { timestamp = nowCtimeTrimmed(); }

void Message::display() const {
    cout << "[" << timestamp << "] "
         << sender << ": " << content
         << " [" << status << "]\n";
}

void Message::addEmoji(string emojiCode) {
    content += " " + emojiCode;
}
