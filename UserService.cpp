#include "UserService.h"

UserService * UserService::instance = nullptr;

UserService * UserService::getInstance() {
    if(instance == nullptr){
        instance = new UserService;
    }
    return instance;
}

UserService::UserService() {}

void UserService::addUser(const string& userId,const std::string &name,const std::string &passHash) {
    User *user = new User(userId,name,passHash);

    json usersArray;
    ifstream users("users.json");
    users >> usersArray;
    users.close();

    json userCredentials;
    userCredentials[user->getUserID()] = {
            {"Name",user->getUserName()},
            {"Password",user->getUserPassword()}
    };

    usersArray.push_back(userCredentials);
    ofstream usersJson("users.json");
    usersJson << usersArray.dump(4);
    usersJson.close();


}

void UserService::removeUser(int userId) {}

void UserService::addFriendRequest(int fromUserId, int toUserId) {}

void UserService::approveFriendRequest(int fromUserId, int toUserId) {

}

void UserService::rejectFriendRequest(int fromUserId, int toUserId) {}

void UserService::displayUser(const unordered_map<int, User *> &usersById) {}