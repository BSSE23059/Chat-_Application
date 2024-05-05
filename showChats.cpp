#include "showChats.h"

void displayPrivateChats(string username, string name, string password){

    UserService *userService = UserService::getInstance();
    string filename = username + ".json";
    ifstream userChatsFile(filename);
    json userChats;
    userChatsFile >> userChats;
    userChatsFile.close();

    cout << setw(5) << "______________________________________________________" << endl;
    cout << setw(5) << "                                                      " << endl;
    cout << setw(5) << "                       Chats                          " << endl;
    cout << setw(5) << "______________________________________________________" << endl;

    if (userChats.size() > 1 && userChats[1].contains("Private Chats")) {
        json privateChats = userChats[1]["Private Chats"];
        int chatIndex = 1;
        for (const auto& chat : privateChats) {
            // Iterate over each private chat
            for (auto it = chat.begin(); it != chat.end(); it++) {
                if (it.key() != username) {
                    cout << setw(7) << chatIndex << ". " << it.key() << endl;
                    chatIndex++;
                }
            }
        }
    } else {
        cout << "No private chats found for user: " << username << endl;
    }
    string chatName;
    bool validChatName = false;
    do {
        cout << "Enter chat name: ";
        cin >> chatName;
        validChatName = false;
        if (userChats.size() > 1 && userChats[1].contains("Private Chats")) {
            json privateChats = userChats[1]["Private Chats"];
            for (const auto& chat : privateChats) {
                // Iterate over each private chat
                for (auto it = chat.begin(); it != chat.end(); it++) {
                    if (it.key() == chatName) {
                        validChatName = true;
                        string message;
                        cin.ignore();

                        while(true){

                            system("clear");
                            Sleep(1000);
                            userService->displayMessages(username,chatName);
                            cout << "Send message ('0' to exit): ";
                            getline(cin,message);
                            if (message == "0") {
                                break; // Exit the send message loop
                            }
                            // Send message logic here
                            time_t now = time(0);
                            tm* localTime = localtime(&now);
                            string date = to_string(localTime->tm_hour) + ":"+ to_string(localTime->tm_min);
                            Message messageObj(message,date);
                            userService->sendMessage(messageObj.getMessageContent(),messageObj.getMessageTime(),username,chatName);

                        }
                        break;
                    }
                }
                if (validChatName) {
                    break;
                }
            }
        }
        if (!validChatName) {
            cout << "Invalid chat name. Please enter a valid one." << endl;
        }
    } while (!validChatName);

}

void displayGroupChats(string username, string name, string password){
    UserService *userService = UserService::getInstance();
    string filename = username + ".json";
    ifstream userChatsFile(filename);
    json userChats;
    userChatsFile >> userChats;
    userChatsFile.close();

    cout << setw(5) << "______________________________________________________" << endl;
    cout << setw(5) << "                                                      " << endl;
    cout << setw(5) << "                       Chats                          " << endl;
    cout << setw(5) << "______________________________________________________" << endl;

    if (userChats.size() > 1 && userChats[2].contains("Group Chats")) {
        json privateChats = userChats[2]["Group Chats"];
        int chatIndex = 1;
        for (const auto& chat : privateChats) {
            // Iterate over each private chat
            for (auto it = chat.begin(); it != chat.end(); it++) {
                if (it.key() != username) {
                    cout << setw(7) << chatIndex << ". " << it.key() << endl;
                    chatIndex++;
                }
            }
        }
    } else {
        cout << "No Group chats found for user: " << username << endl;
    }
    string groupChatName;
    bool validChatName = false;
    do {
        cout << "Enter Group name: ";
        cin >> groupChatName;
        validChatName = false;
        if (userChats.size() > 1 && userChats[2].contains("Group Chats")) {
            json privateChats = userChats[2]["Group Chats"];
            for (const auto& chat : privateChats) {
                // Iterate over each private chat
                for (auto it = chat.begin(); it != chat.end(); it++) {
                    if (it.key() == groupChatName) {
                        validChatName = true;
                        string message;
                        cin.ignore();

                        char stop;
                        int choice;
                        do{
                            cout << "__________________________________" << endl;
                            cout << "                                  " << endl;
                            cout << "         "<< groupChatName << "         " << endl;
                            cout << "__________________________________" << endl;
                            cout << "1. View Participants." << endl;
                            cout << "2. Send message." << endl;
                            cout << "Enter your choice :";
                            cin >> choice;
                            if(choice == 1){
                                userService->viewGroupMembers(groupChatName,username);
                            } else if(choice == 2){
                                cin.ignore();
                                while(true) {
                                    userService->displayGroupMessages(username,groupChatName);
                                    cout << "Send message ('0' to exit): ";
                                    getline(cin, message);
                                    if (message == "0") {
                                        break; // Exit the send message loop
                                    }
                                    // Send message logic here
                                    cout << "Message sent :" << message << endl;
                                    time_t now = time(0);
                                    tm *localTime = localtime(&now);
                                    string date = to_string(localTime->tm_hour) + ":" + to_string(localTime->tm_min);
                                    Message messageObj(message,date);
                                    userService->sendMessageToGroup(messageObj.getMessageContent(),messageObj.getMessageTime(),username,groupChatName);
                                }
                            }
                            cout << "Do you want to continue(Y/N) :";
                            cin >> stop;

                        }while(stop == 'Y' || stop == 'y');
                        break;
                    }
                }
                if (validChatName) {
                    break;
                }
            }
        }
        if (!validChatName) {
            cout << "Invalid chat name. Please enter a valid one." << endl;
        }
    } while (!validChatName);
}