#ifndef CHAT__APPLICATION_GROUPCHAT_H
#define CHAT__APPLICATION_GROUPCHAT_H
#include <iostream>
#include "Chat.h"
using namespace std;

class GroupChat : public Chat{
public:
    void addUser(string user);
    void removeUser(string user);
    void displayUsers() override;
    void addMessage(Message* message) override;
};


#endif //CHAT__APPLICATION_GROUPCHAT_H
