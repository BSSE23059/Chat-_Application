#ifndef CHAT__APPLICATION_CREATECHATS_H
#define CHAT__APPLICATION_CREATECHATS_H
#include <iostream>
#include <fstream>
#include "User.h"
#include "nlohmann/json.hpp"
#include "PrivateChat.h"
#include "UserService.h"
using json = nlohmann::json;
using namespace std;

void createChats(string username, string name, string pass);
string toSmall(const std::string& str);
#endif //CHAT__APPLICATION_CREATECHATS_H
