#include "Message.h"


Message::Message(std::string messageContent, std::string time) {
    content = messageContent;
    timestamp = time;
}

string Message::getMessageContent() {
    return content;
}

string Message::getMessageTime() {
    return timestamp;
}

void Message::setMessageContent(string messageContent) {
    content = messageContent;
}

void Message::setMessageTime(string time) {
    timestamp = time;
}