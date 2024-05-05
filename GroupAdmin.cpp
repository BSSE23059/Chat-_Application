#include "GroupAdmin.h"

GroupAdmin::GroupAdmin(std::string username) {
    setUserID(username);
    isAdmin = true;
}

bool GroupAdmin::getAdminStatus() {
    return isAdmin;

}

void GroupAdmin::setAdminStatus(bool admin) {
    isAdmin = admin;
}

void GroupAdmin::addGroupMembers(User *member,string& groupName) {
    auto it = groupChats.find(groupName);
    if(it != groupChats.end()){
        it->second->addUser(member->getUserID());
    } else {
        cout << "Group chat " << groupName << " does not exist." << endl;
    }
}

void GroupAdmin::removeGroupMember(std::string &memberName, std::string &groupName) {
    auto it = groupChats.find(groupName);
    if(it != groupChats.end()){
        it->second->removeUser(memberName);
    } else {
        cout << "Group chat " << groupName << " does not exist." << endl;
    }
}

void GroupAdmin::addAdmin(std::string &memberName, string& groupName) {
    auto it = groupChats.find(groupName);
    if(it != groupChats.end()){
        it->second->removeUser(memberName);
    } else {
        cout << "Group chat " << groupName << " does not exist." << endl;
    }
    auto *admin = new GroupAdmin(memberName);
    admin->addGroupMembers(admin,groupName);
}