#ifndef CHAT__APPLICATION_PRIVATECHAT_H
#define CHAT__APPLICATION_PRIVATECHAT_H
#include <iostream>
#include "Chat.h"
using namespace std;

class PrivateChat : public Chat{
public:
    PrivateChat(string firstUser, string secondUser);
    void displayUsers() override;
    void addMessage(Message* message) override;
};


#endif //CHAT__APPLICATION_PRIVATECHAT_H
