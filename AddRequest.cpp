#include "AddRequest.h"


AddRequest::AddRequest(int fromId, int toId, RequestStatus status, time_t time) {
    fromUserId = fromId;
    toUserId = toId;
    this -> requestStatus = status;
    timeStamp = time;
}