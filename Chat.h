#ifndef CHAT__APPLICATION_CHAT_H
#define CHAT__APPLICATION_CHAT_H
#include <iostream>
#include <vector>
#include "Message.h"
using namespace std;

class Chat {
private:
    int chatId;
    vector <Message*> messages;
protected:
    vector <int> users;
public:
    explicit Chat(int id);
    vector<int>& getUsers();
};


#endif //CHAT__APPLICATION_CHAT_H
