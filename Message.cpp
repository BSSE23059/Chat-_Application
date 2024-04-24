#include "Message.h"

template<typename T>
T Message<T>::getMessageContent() {
    return content;
}

template<typename T>
time_t Message<T>::getMessageTime() {
    return timestamp;
}

template<typename T>
void Message<T>::setMessageContent(T messageContent) {
    content = messageContent;
}

template<typename T>
void Message<T>::setMessageTime(time_t time) {
    timestamp = time;
}