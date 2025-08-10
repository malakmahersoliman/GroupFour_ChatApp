
#include "../include/PrivateChat.h"
#include<iostream>

using namespace std;
// ========================
//     PRIVATE CHAT CLASS
// ========================


PrivateChat::PrivateChat(string u1, string u2) {
    // TODO: Implement constructor
	user1 = u1;
	user2 = u2;

	participants.push_back(u1);
	participants.push_back(u2);

}

void PrivateChat::displayChat() const{
    // TODO: Implement private chat display

	if (messages.empty())
	{
		cout << "No Messages \n";
		return;
	}
	else
	{
		for (int i = 0; i<messages.size(); i++)
		{
			messages[i].display();
		}
	}
}

void PrivateChat::showTypingIndicator(const std::string& username) const {
    // TODO: Implement typing indicator
	cout << username << "Typing...";
}

