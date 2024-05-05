#include "userInterface.h"

void userInterface(string userName,string name, string password){
    int choice;
    char stop;
    do{
        system("clear");
        cout << "__________________________________________________________" << endl;
        cout << "                                                          " << endl;
        cout << "                   Welcome to Chat-up                     " << endl;
        cout << "__________________________________________________________" << endl;
        cout << "1-> Create a chat room." << endl;
        cout << "2-> Private Chats." << endl;
        cout << "3-> Group Chats." << endl;
        cout << "4-> Exit." << endl;
        cout << "Enter your choice :";
        cin >> choice;

        switch(choice){
            case 1:{
                createChats(userName,name,password);
                break;
            }
            case 2:{
                displayPrivateChats(userName,name,password);
                break;
            }
            case 3:{
                displayGroupChats(userName,name,password);
                break;
            }
            default :{
                cout << "Invalid input, please enter a valid input....." << endl;
                break;
            }
        }
        cout << "Do you want to continue(Y/N) :";
        cin >> stop;
    }while(stop == 'Y' || stop == 'y');

}