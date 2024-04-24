#ifndef CHAT__APPLICATION_USERSERVICE_H
#define CHAT__APPLICATION_USERSERVICE_H
#include <iostream>
#include "User.h"
#include <fstream>
#include <unordered_map>
#include "nlohmann/json.hpp"
using json = nlohmann::json;
using namespace std;

class UserService {
private:
    static UserService* instance;
    unordered_map<int, User*> usersById;
    UserService();

public:
    static UserService* getInstance();
    void addUser(const string& userId,const std::string& name,const std::string& passHash);
    void displayUser(const unordered_map<int, User*>& usersById);
    void removeUser(int userId);
    void addFriendRequest(int fromUserId, int toUserId);
    void approveFriendRequest(int fromUserId, int toUserId);
    void rejectFriendRequest(int fromUserId, int toUserId);
};


#endif //CHAT__APPLICATION_USERSERVICE_H
