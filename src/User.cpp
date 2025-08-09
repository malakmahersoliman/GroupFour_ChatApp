#include "../include/User.h"


static string formatTime(time_t t) {
    return string(ctime(&t));
}

User::User() {
    username = "";
    password = "";
    phoneNumber = "";
    status = "Offline";
    lastSeen = "Never";
}

User::User(string uname, string pwd, string phone) {
    username = uname;
    password = pwd;
    phoneNumber = phone;
    status = "Offline";
    lastSeen = "Never";
}

string User::getUsername() const { 
    return username; 
}
string User::getPhoneNumber() const {
     return phoneNumber; 
    }
string User::getStatus() const { 
    return status;
 }
string User::getLastSeen() const {
     return lastSeen;
     }
void User::setStatus(string newStatus) { 
    status = newStatus; 
}
void User::setPhoneNumber(string phone) { 
    phoneNumber = phone; 
}
void User::updateLastSeen() { 
    lastSeen = formatTime(); 
}
bool User::checkPassword(string pwd) const { 
    return pwd == password; 
}
void User::changePassword(string newPwd) { 
    password = newPwd;
 }
