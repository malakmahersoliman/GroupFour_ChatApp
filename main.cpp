#include <iostream>

#include "src/User.cpp"
#include "src/Message.cpp"
#include "src/Chat.cpp"
#include "src/PrivateChat.cpp"
#include "src/GroupChat.cpp"
#include "src/WhatsApp.cpp"

using namespace std;

// ========================
//          MAIN
// ========================
int main() {
    WhatsApp whatsapp;
    whatsapp.run();
    return 0;
}
