#include "UserService.h"

UserService * UserService::instance = nullptr;

UserService * UserService::getInstance() {
    if(instance == nullptr){
        instance = new UserService;
    }
    return instance;
}

string toLower(const std::string& str) {
    string result = str;
    transform(result.begin(), result.end(), result.begin(), [](unsigned char c) { return tolower(c); });
    return result;
}

UserService::UserService() = default;

void UserService::addUser(User* user) {
    usersById[user->getUserID()] = user;

    ofstream addUsersToTxt("users.txt",ios::app);
    addUsersToTxt << user->getUserID() << endl;
    addUsersToTxt.close();

    string filename = toLower(user->getUserID()) + ".json";
    json userData;

    json userCredentials;
    userCredentials[user->getUserID()] = {
            {"Name",user->getUserName()},
            {"Password",user->getUserPassword()}
    };

    json userPrivateChats;
    userPrivateChats["Private Chats"] = json::array();

    json groupChats;
    groupChats["Group Chats"] = json::array();
    userData.push_back(userCredentials);
    userData.push_back(userPrivateChats);
    userData.push_back(groupChats);

    ofstream usersJson(filename);
    usersJson << userData.dump(4);
    usersJson.close();

}

void UserService::removeUser(int userId) {

}


void UserService::addPrivateChat(PrivateChat *privateChat) {

    if(usersById.find(privateChat->getUsers()[0]) != usersById.end() && usersById.find(privateChat->getUsers()[0]) != usersById.end()){

        User *user1 = usersById[privateChat->getUsers()[0]];
        User *user2 = usersById[privateChat->getUsers()[1]];

        user1->addPrivateChat(privateChat->getUsers()[1],privateChat);
        user2->addPrivateChat(privateChat->getUsers()[0],privateChat);
    }

    string firstFile = toLower(privateChat->getUsers()[0]) + ".json";
    ifstream firstUser(firstFile);
    cout << firstFile << endl;
    json firstUserData;
    firstUser >> firstUserData;
    cout << firstUserData << endl;
    firstUser.close();

    json &privateChats = firstUserData[1]["Private Chats"];

    json privateChatData;
    privateChatData[privateChat->getUsers()[1]] = {
            {"You",json::array()},
            {privateChat->getUsers()[1],json::array()}
    };


    privateChats.push_back(privateChatData);

    ofstream outPrivateChat(firstFile);
    outPrivateChat << firstUserData.dump(4) << endl;
    outPrivateChat.close();

    string secondFile = toLower(privateChat->getUsers()[1]) + ".json";
    ifstream secondUser(secondFile);
    json secondUserData;
    secondUser >> secondUserData;
    secondUser.close();

    json &privateChats1 = secondUserData[1]["Private Chats"];

    json privateChatData1;
    privateChatData1[privateChat->getUsers()[0]] = {
            {"You",json::array()},
            {privateChat->getUsers()[0],json::array()}
    };

    privateChats1.push_back(privateChatData1);

    ofstream outPrivateChat1(secondFile);
    outPrivateChat1 << secondUserData.dump(4) << endl;
    outPrivateChat1.close();
    cout << "Private Chat with " << privateChat->getUsers()[1] << " has been created successfully." << endl;


}

void UserService::addFriendRequest(int fromUserId, int toUserId) {}

void UserService::approveFriendRequest(int fromUserId, int toUserId) {

}

void UserService::rejectFriendRequest(int fromUserId, int toUserId) {}

void UserService::displayUser(unordered_map<int, User *> &users) {}

void UserService::loginUser(std::string &userName, const std::string &password) {
    string filename = toLower(userName) + ".json";

    json users;
    ifstream loginUser(filename);
    loginUser >> users;
    loginUser.close();

    if (!users.empty()) {
        json userCredentials = users[0];
        if (userCredentials.find(userName) != userCredentials.end()) {
            json userInfo = userCredentials[userName];
            string name = userInfo["Name"];
            if (userInfo["Password"] == password) {
                userInterface(userName,name,password);
            }
            else {
                cout << "Password is incorrect. Please try again." << endl;
            }
        }
    }

}

void UserService::sendMessage(string &message, string &date, string &fromUser, string &toUser) {
    if(usersById.find(fromUser) != usersById.end() && usersById.find(toUser) != usersById.end()){
        User *user = usersById[fromUser];
        user->messageUser(toUser,message);
    }

    string secondUser = toLower(toUser);
    string firstUserFile = fromUser + ".json";
    ifstream getDataFromFirstUserFile(firstUserFile);
    json getFirstUserData;
    getDataFromFirstUserFile >> getFirstUserData;
    getDataFromFirstUserFile.close();

    for(auto& privateChat : getFirstUserData[1]["Private Chats"]){
        if(privateChat.contains(toUser)){
            privateChat[toUser]["You"].push_back({
                {message,date}
            });
            break;
        }
    }

    ofstream senderOutFile(firstUserFile);
    senderOutFile << getFirstUserData.dump(4) << endl;
    senderOutFile.close();

    string secondUserFile = secondUser + ".json";
    ifstream getDataFromSecondUserFile(secondUserFile);
    json secondUserData;
    getDataFromSecondUserFile >> secondUserData;
    getDataFromSecondUserFile.close();

    for(auto& privateChat : secondUserData[1]["Private Chats"]){
        if(privateChat.contains(fromUser)){
            privateChat[fromUser][fromUser].push_back({
                {message,date}
            });
            break;
        }
    }

    ofstream secondUserOutData(secondUserFile);
    secondUserOutData << secondUserData.dump(4) << endl;
    secondUserOutData.close();

}