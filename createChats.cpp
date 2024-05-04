#include "createChats.h"


void createChats(string username,string name, string pass){
    int choice;
    char stop;
    do{
        system("clear");
        UserService* userService = UserService::getInstance();
        cout << "______________________________________________________" << endl;
        cout << "                                                      " << endl;
        cout << "                 Create Chat-Rooms                    " << endl;
        cout << "______________________________________________________" << endl;
        cout << "1-> Create a private chat." << endl;
        cout << "2-> Create a group chat." << endl;
        cout << "3-> Exit." << endl;
        cout << "Enter your choice :";
        cin >> choice;
        switch(choice){
            case 1:{

                string friendName;
                ifstream verifyUser("users.txt");
                string usernames;
                cout << "Enter your friend name :";
                cin >> friendName;

                while (getline(verifyUser, usernames)) {
                    if (friendName == usernames) {
                        string friendFile = toSmall(friendName) + ".json";
                        ifstream getFriendData(friendFile);
                        json friendData;
                        getFriendData >> friendData;
                        getFriendData.close();

                        if (!friendData.empty()) {
                            json userCredentials = friendData[0];
                            if (userCredentials.find(friendName) != userCredentials.end()) {
                                json userInfo = userCredentials[friendName];
                                string fName = userInfo["Name"];
                                string friendPass = userInfo["Password"];
                                User user1(friendName, fName, friendPass);
                                User user(username, name, pass);

                                auto *privateChat = new PrivateChat(user.getUserID(),user1.getUserID());
                                userService->addPrivateChat(privateChat);
                            }
                        }
                        break;
                    } else {
                        cout << "Friend with name " << friendName << " does not exist." << endl;
                    }
                }
                break;
            }
            case 2:{

                int numOfGroupMembersToAdd;
                string memberName,groupChatName, usernames,memName,memPassword;
                ifstream verifyUser("users.txt");
                cout << "Enter the name of group chat :";
                cin.ignore();
                getline(cin,groupChatName);
                cout << "Enter the number of members you want to add :";
                cin >> numOfGroupMembersToAdd;
                auto *groupChat = new GroupChat(groupChatName);
                User user(username, name, pass);
                groupChat->addUser(user.getUserID());
                cin.ignore();
                for(int addGroupMember=0;addGroupMember<numOfGroupMembersToAdd;addGroupMember++){
                    cout << "Enter the name of member "<< addGroupMember + 2 << " :";
                    getline(cin,memberName);
                    while (getline(verifyUser, usernames)) {
                        if (memberName == usernames) {
                            string memberFile = toSmall(memberName) + ".json";
                            ifstream getFriendData(memberFile);
                            json memberData;
                            getFriendData >> memberData;
                            getFriendData.close();

                            if (!memberData.empty()) {
                                json userCredentials = memberData[0];
                                if (userCredentials.find(memberName) != userCredentials.end()) {
                                    json userInfo = userCredentials[memberName];
                                    memName = userInfo["Name"];
                                    memPassword = userInfo["Password"];
                                    User members(memberName, memName, memPassword);
                                    groupChat->addUser(members.getUserID());
                                } else {
                                    cout << "Member with name " << memberName << " does not found in json." << endl;
                                }
                            } else {
                                cout << "Member " << memberName << " contains data." << endl;
                            }
                            break;
                        }
                    }
                }
                userService->addGroupChat(groupChat);
                break;
            }

        }
        cout << "Do you want to continue(Y/N) :";
        cin >> stop;
    }while(stop == 'Y' || stop == 'y');

}


string toSmall(const string& str){
    string result = str;
    transform(result.begin(), result.end(), result.begin(), [](unsigned char c) { return tolower(c); });
    return result;
}