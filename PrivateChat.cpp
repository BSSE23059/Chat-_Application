
#include "PrivateChat.h"

PrivateChat::PrivateChat(string firstUser, string secondUser) {
    this->getUsers().push_back(firstUser);
    this->getUsers().push_back(secondUser);
}

void PrivateChat::displayUsers() {
    for(int i=0;i<users.size();i++){
        cout << i+1 << ". "<< users[i] << endl;
    }
}

void PrivateChat::addMessage(Message *message) {
    getMessages().push_back(message);
}