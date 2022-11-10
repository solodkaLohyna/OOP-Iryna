#pragma once
#include <iostream>
#include <string.h>

using namespace std;
/*point 17*/

#pragma once
class Room {
    friend class Office;
    string roomName;

public:
    Room();
    void setRoom(const string newRoom);

    void printRoom();
    ~Room();
};


