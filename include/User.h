#ifndef USER_H
#define USER_H
#include <ctime>
#include <string>

using namespace std;

static string formatTime(time_t t = time(nullptr));
class User {
private:
    string username;
    string password;
    string phoneNumber;
    string status;
    string lastSeen;

public:
    User();
    User(string uname, string pwd, string phone);

    string getUsername() const;
    string getPhoneNumber() const;
    string getStatus() const;
    string getLastSeen() const;

    bool checkPassword(string pwd) const;
    void setStatus(string newStatus);
    void setPhoneNumber(string phone);
    void updateLastSeen();
    void changePassword(string newPwd);
};

#endif
