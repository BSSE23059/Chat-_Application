#include "GroupChat.h"

GroupChat::GroupChat(std::string name) {
    groupName = name;
}


void GroupChat::addUser(string user) {
    getUsers().push_back(user);
}

void GroupChat::removeUser(string user) {
    for(auto& removeUserFromUsers : users){
        if(removeUserFromUsers == user){
            removeUserFromUsers.erase(removeUserFromUsers.begin());
        }
    }
}

const string GroupChat::getGroupName() const {
    return groupName;
}

void GroupChat::setChatName(std::string name) {
    groupName = name;
}

void GroupChat::displayUsers() {
    for(int i=0;i<users.size();i++){
        cout << i+1 << ". " << users[i] << endl;
    }
}

void GroupChat::addMessage(Message *message) {
    getMessages().push_back(message);
}