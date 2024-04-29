#include "showChats.h"

void displayChats(string username, string name, string password){

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
                        while (true) {
                            cout << "Send message ('0' to exit): ";
                            getline(cin,message);
                            if (message == "0") {
                                break; // Exit the send message loop
                            }
                            // Send message logic here
                            cout << "Message sent: " << message << endl;
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

