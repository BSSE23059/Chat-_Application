#ifndef CHAT__APPLICATION_PRIVATECHAT_H
#define CHAT__APPLICATION_PRIVATECHAT_H
#include <iostream>
#include "Chat.h"
using namespace std;

class PrivateChat : public Chat{
public:
    PrivateChat(int firstUser, int secondUser);
};


#endif //CHAT__APPLICATION_PRIVATECHAT_H
