#include "User.h"

User::User(string id, std::string n, std::string pass) {
    ID = id;
    name = n;
    password = pass;
}

User::User() = default;


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

void User::messageUser(string friendUserName, const std::string &message) {
    int chatIndex = 1;
    for (auto it = privateChats.begin(); it != privateChats.end(); it++) {
        const std::string& username = it->first;
        if(friendUserName == username){
            PrivateChat* privateChat = privateChats[username];
            chatIndex++;
            time_t now = time(0);
            tm* localTime = localtime(&now);
            string date = to_string(localTime->tm_year + 1900) + "-" + to_string(localTime->tm_mon + 1) + "-" + to_string(localTime->tm_mday) + "    " +
                          to_string(localTime->tm_hour) + ":"+ to_string(localTime->tm_min);
            auto *message1 = new Message(message,date);

            privateChat->addMessage(message1);
        } else {
            cout << "Friend with name " << friendUserName << " not found." << endl;

        }

    }
}
void User::messageGroup(int groupId, const std::string &message) {}

void User::sendFriendRequest(int friendId, int toId) {}

void User::approveFriendRequest(int friend_id) {}

void User::receiveFriendRequest(int friendId) {}

void User::rejectFriendRequest(int friend_id) {}

const unordered_map<string, PrivateChat *> &User::getPrivateChats() const {
    return privateChats;
}

void User::addPrivateChat(std::string friendUsername, PrivateChat *privateChat) {
    privateChats[friendUsername] = privateChat;
}

void User::displayChats() {
    int chatIndex = 1;
    for (auto it = privateChats.begin(); it != privateChats.end();it++) {
        const std::string& username = it->first;
        cout << chatIndex << ". " << username << endl;
        chatIndex++;
    }
}

bool User::getAdminStatus() {
    return false;
}

const unordered_map<string, GroupChat *> &User::getGroupChats() const {
    return groupChats;
}
