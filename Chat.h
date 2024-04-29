#ifndef CHAT__APPLICATION_CHAT_H
#define CHAT__APPLICATION_CHAT_H
#include <iostream>
#include <vector>
#include "Message.h"
using namespace std;

class Chat {
private:
    vector <Message*> messages;
protected:
    vector <string> users;
public:
    vector<string>& getUsers();
    vector<Message*>& getMessages();
    virtual void displayUsers() = 0;
    virtual void addMessage(Message* message) = 0;
};


#endif //CHAT__APPLICATION_CHAT_H
