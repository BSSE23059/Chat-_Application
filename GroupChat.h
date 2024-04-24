#ifndef CHAT__APPLICATION_GROUPCHAT_H
#define CHAT__APPLICATION_GROUPCHAT_H
#include <iostream>
#include "Chat.h"
using namespace std;

class GroupChat : public Chat{
public:
    void addUser(int user);
    void removeUser(int user);
};


#endif //CHAT__APPLICATION_GROUPCHAT_H
