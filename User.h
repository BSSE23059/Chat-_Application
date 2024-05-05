#ifndef CHAT__APPLICATION_USER_H
#define CHAT__APPLICATION_USER_H
#include <iostream>
#include <vector>
#include <unordered_map>
#include "PrivateChat.h"
#include "GroupChat.h"
#include "Message.h"
using namespace std;

class User {
private:
    string name;
    string ID;
    string password;
    unordered_map<string, User*> friendsById;
protected:
    unordered_map<string, PrivateChat*> privateChats;
    unordered_map<string, GroupChat*> groupChats;
public:
    User(string id, std::string  n, std::string  pass);
    User();
    string getUserID() const;
    string getUserName() const;
    string getUserPassword() const;
    const unordered_map<string, GroupChat *> &getGroupChats() const;
    bool getAdminStatus();
    const unordered_map<string, PrivateChat *> &getPrivateChats() const;
    void setUserID(const string& userID);
    void setUserName(const string& userName);
    void setUserPassword(const string& pass);
    void messageUser(string friendUserName, const std::string& message);
    void messageGroup(int groupId, const std::string& message);
    void sendFriendRequest(int friendId,int toId);
    void receiveFriendRequest(int friendId);
    void approveFriendRequest(int friend_id);
    void rejectFriendRequest(int friend_id);
    void addPrivateChat(string friendUsername, PrivateChat* privateChat);
    void displayChats();
};


#endif //CHAT__APPLICATION_USER_H
