#ifndef CHAT__APPLICATION_GROUPADMIN_H
#define CHAT__APPLICATION_GROUPADMIN_H
#include <iostream>
#include "User.h"
using namespace std;

class GroupAdmin : public User{
private:
    bool isAdmin;
public:
    GroupAdmin(string username);
    bool getAdminStatus();
    void setAdminStatus(bool admin);
    void addGroupMembers(User* member, string& groupName);
    void removeGroupMember(string& memberName, string& groupName);
    void addAdmin(string& memberName, string& groupName);
};


#endif //CHAT__APPLICATION_GROUPADMIN_H
