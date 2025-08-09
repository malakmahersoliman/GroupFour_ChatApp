#include <iostream>
#include <string>
#include <ctime>
#include "../include/Message.h"

using namespace std;

// ========================
//      MESSAGE CLASS
// ========================



// Default constructor
Message::Message() {
    // TODO: Implement default constructor
}

// Parameterized constructor
Message::Message(string sndr, string cntnt) {
    // TODO: Implement parameterized constructor
}

string Message::getContent() const {
    // TODO: Implement getter
    return "";
}

string Message::getSender() const {
    // TODO: Implement getter
    return "";
}

string Message::getTimestamp() const {
    // TODO: Implement getter
    return "";
}

string Message::getStatus() const {
    // TODO: Implement getter
    return "";
}

Message* Message::getReplyTo() const {
    // TODO: Implement getter
    return nullptr;
}

void Message::setStatus(string newStatus) {
    // TODO: Implement setter
}

void Message::setReplyTo(Message* msg) {
    // TODO: Implement setter
}

void Message::updateTimestamp() {
    // TODO: Implement timestamp update
}

void Message::display() const {
    // TODO: Implement message display
}

void Message::addEmoji(string emojiCode) {
    // TODO: Implement emoji support
}
