#ifndef CHAT__APPLICATION_MESSAGE_H
#define CHAT__APPLICATION_MESSAGE_H
#include <iostream>
using namespace std;
template<typename T>

class Message {
private:
    T content;
    time_t timestamp;
public:
    Message(T messageContent, time_t time);
    T getMessageContent();
    time_t getMessageTime();
    void setMessageContent(T messageContent);
    void setMessageTime(time_t time);
};


#endif //CHAT__APPLICATION_MESSAGE_H
