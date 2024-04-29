#ifndef CHAT__APPLICATION_SHOWCHATS_H
#define CHAT__APPLICATION_SHOWCHATS_H
#include <iostream>
#include "UserService.h"
#include "User.h"
#include <fstream>
#include "nlohmann/json.hpp"
using json = nlohmann::json;

void displayChats(string username, string name, string password);

#endif //CHAT__APPLICATION_SHOWCHATS_H
