#include <iostream>
#include "UserService.cpp"
#include "User.cpp"
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

                break;
            }
            case 2:{
                string name,ID,password;
                cout << "Enter your name :";
                cin >> name;
                cout << "Enter your username :";
                cin >> ID;
                cout << "Enter password :";
                cin >> password;
                userService->addUser(ID,name,password);
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