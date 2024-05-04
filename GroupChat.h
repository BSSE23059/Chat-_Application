#ifndef CHAT__APPLICATION_GROUPCHAT_H
#define CHAT__APPLICATION_GROUPCHAT_H
#include <iostream>
#include "Chat.h"
using namespace std;

class GroupChat : public Chat{
private:
    string groupName;
public:
    explicit GroupChat(string name);
    void addUser(string user);
    void removeUser(string user);
    const string getGroupName() const;
    void setChatName(string name);
    void displayUsers() override;
    void addMessage(Message* message) override;
};


#endif //CHAT__APPLICATION_GROUPCHAT_H
