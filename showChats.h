#ifndef CHAT__APPLICATION_SHOWCHATS_H
#define CHAT__APPLICATION_SHOWCHATS_H
#include <iostream>
#include "UserService.h"
#include "User.h"
#include <fstream>
#include <thread>
#include <windows.h>
#include <chrono>
#include "nlohmann/json.hpp"
using json = nlohmann::json;

void displayPrivateChats(string username, string name, string password);
void displayGroupChats(string username, string name, string password);

#endif //CHAT__APPLICATION_SHOWCHATS_H
