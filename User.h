#ifndef CHAT__APPLICATION_USER_H
#define CHAT__APPLICATION_USER_H
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class User {
private:
    string name;
    string ID;
    string password;
    unordered_map<int, User*> friendsById;

public:
    User(string id, std::string  n, std::string  pass);
    string getUserID() const;
    string getUserName() const;
    string getUserPassword() const;
    void setUserID(const string& userID);
    void setUserName(const string& userName);
    void setUserPassword(const string& pass);
    void messageUser(int friendId, const std::string& message);
    void messageGroup(int groupId, const std::string& message);
    void sendFriendRequest(int friendId,int toId);
    void receiveFriendRequest(int friendId);
    void approveFriendRequest(int friend_id);
    void rejectFriendRequest(int friend_id);
};


#endif //CHAT__APPLICATION_USER_H
