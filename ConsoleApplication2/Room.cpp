#include "Room.h"
Room::Room() {}
void Room::setRoom(const string newRoom) { roomName = newRoom; }

void Room::printRoom() { cout << roomName << " "; }
Room::~Room() { cout << "destructor for " << roomName; }