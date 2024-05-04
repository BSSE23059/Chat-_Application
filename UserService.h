#ifndef CHAT__APPLICATION_USERSERVICE_H
#define CHAT__APPLICATION_USERSERVICE_H
#include <iostream>
#include "User.h"
#include <fstream>
#include <unordered_map>
#include "PrivateChat.h"
#include "GroupChat.h"
#include "userInterface.h"
#include "nlohmann/json.hpp"
using json = nlohmann::json;
using namespace std;

class UserService {
private:
    static UserService* instance;
    unordered_map<string, User*> usersById;
    UserService();
public:
    static UserService* getInstance();
    void addUser(User* user);
    void loginUser(string& userName, const string& password);
    void sendMessage(string& message, string& date, string& fromUser, string& toUser);
    void displayMessages(string& fromUser,string& toUser);
    void displayUser(unordered_map<int, User*>& usersById);
    void removeUser(int userId);
    void addPrivateChat(PrivateChat* privateChat);
    void addGroupChat(GroupChat* groupChat);
    void addFriendRequest(int fromUserId, int toUserId);
    void approveFriendRequest(int fromUserId, int toUserId);
    void rejectFriendRequest(int fromUserId, int toUserId);
    friend string toLower(const std::string& str);
};




#endif //CHAT__APPLICATION_USERSERVICE_H
