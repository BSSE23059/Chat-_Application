#ifndef CHAT__APPLICATION_MESSAGE_H
#define CHAT__APPLICATION_MESSAGE_H
#include <iostream>
using namespace std;

class Message {
private:
    string content;
    string timestamp;
public:
    Message(string messageContent, string time);
    string getMessageContent();
    string getMessageTime();
    void setMessageContent(string messageContent);
    void setMessageTime(string time);
};


#endif //CHAT__APPLICATION_MESSAGE_H
