#include "User.h"

User::User(string id, std::string n, std::string pass) {
    ID = id;
    name = n;
    password = pass;
}

string User::getUserID() const {
    return ID;
}

string User::getUserName() const {
    return name;
}

string User::getUserPassword() const {
    return password;
}

void User::setUserID(const string& userID) {
    ID = userID;
}

void User::setUserName(const string &userName) {
    name = userName;
}

void User::setUserPassword(const string &pass) {
    password =pass;
}

void User::messageUser(int friendId, const std::string &message) {}

void User::messageGroup(int groupId, const std::string &message) {}

void User::sendFriendRequest(int friendId, int toId) {}

void User::approveFriendRequest(int friend_id) {}

void User::receiveFriendRequest(int friendId) {}

void User::rejectFriendRequest(int friend_id) {}