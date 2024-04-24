#include "Chat.h"

Chat::Chat(int id) {
    chatId = id;
}

vector<int> & Chat::getUsers() {
    return users;
}