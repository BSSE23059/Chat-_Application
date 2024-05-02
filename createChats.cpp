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
                        cout << friendFile << endl;
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

                                cout << user.getUserID() << endl;
                                cout << user1.getUserID() << endl;
                                auto *privateChat = new PrivateChat(user.getUserID(),user1.getUserID());

                                cout << privateChat->getUsers()[0] << endl;
                                cout << privateChat->getUsers()[1] << endl;
                                userService->addPrivateChat(privateChat);
                            }
                        }
                        break;
                    }
                }
            }
            break;

        }
        cout << "Do you want to continue(Y/N) :";
        cin >> stop;
    }while(stop == 'Y' || stop == 'y');

}


string toSmall(const std::string& str){
    string result = str;
    transform(result.begin(), result.end(), result.begin(), [](unsigned char c) { return tolower(c); });
    return result;
}