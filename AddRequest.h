#ifndef CHAT__APPLICATION_ADDREQUEST_H
#define CHAT__APPLICATION_ADDREQUEST_H
#include <iostream>
using namespace std;

enum class RequestStatus{

    UNREAD = 0,
    READ = 1,
    ACCEPTED = 2,
    REJECTED = 3

};

class AddRequest {
private:
    int fromUserId;
    int toUserId;
    RequestStatus requestStatus;
    time_t timeStamp;
public:
    AddRequest(int fromId, int toId, RequestStatus status, time_t time);
};




#endif //CHAT__APPLICATION_ADDREQUEST_H
