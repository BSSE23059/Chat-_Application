#include "GroupChat.h"

void GroupChat::addUser(string user) {
    getUsers().push_back(user);
}

void GroupChat::removeUser(string user) {

}

void GroupChat::displayUsers() {
    for(int i=0;i<users.size();i++){
        cout << i+1 << ". " << users[i] << endl;
    }
}

void GroupChat::addMessage(Message *message) {
    getMessages().push_back(message);
}