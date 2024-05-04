#include <iostream>
#include "UserService.h"
#include "User.h"
#include "Chat.h"
#include "PrivateChat.h"
#include "GroupChat.h"
#include "userInterface.h"
#include "createChats.h"
#include "showChats.h"
#include "Message.h"
using namespace std;


int main(){
    int choice;
    char stop;

    do{
        system("clear");

        UserService *userService = UserService::getInstance();
        cout << "__________________________________________________" << endl;
        cout << "                                                  " << endl;
        cout << "               Welcome to Chat-up                 " << endl;
        cout << "__________________________________________________" << endl;
        cout << "1 -> Login." << endl;
        cout << "2 -> Signup." << endl;
        cout << "3 -> Exit." << endl;
        cout << "Enter your choice :";
        cin >> choice;
        switch(choice){
            case 1:{
                string username,pass;

                cout << "Enter username :";
                cin >> username;
                cout << "Enter password :";
                cin >> pass;
                userService->loginUser(username,pass);
                break;
            }
            case 2:{
                string name,ID,password;
                cout << "Enter your name :";
                cin >> name;
                cout << "Enter your username :";
                cin >> ID;
                ifstream verifyUserNames("users.txt");
                string usernames;
                while(getline(verifyUserNames,usernames)){
                    if(ID == usernames){
                        cout << "Username already exists, Please enter another username :";
                        cin >> ID;

                        verifyUserNames.clear();
                        verifyUserNames.seekg(0,ios::beg);
                    }
                }
                verifyUserNames.close();
                cout << "Enter password :";
                cin >> password;
                auto *user = new User(ID,name,password);
                userService->addUser(user);
                break;
            }
            default:{
                cout << "Invalid Input, Please enter valid input...." << endl;
                break;
            }
        }

        cout << "Do you want to continue(Y/N): ";
        cin >> stop;
    }while(stop == 'y' || stop == 'Y');



    return 0;
}