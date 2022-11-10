#include "Office.h"
using namespace BuildingSpace;
using namespace AreaSpace;

Office::Office(double x, double y, int number, string street_o, string type_o,
    int floor_o)
    : Area(street_o, number, x, y), Building(type_o, floor_o) {
    size = 0;
    /*point 13*/
    cout << "Constructor for office\n";
};

const int Office::getSize() const { return size; }
const Room** Office::getRoom(int& n) const {
    n = size;
    return const_cast<const Room**>(roomList);
}

bool Office::add(const string room) {
    roomList[size] = new Room;
    roomList[size]->setRoom(room);
    size++;
    return true;
}
/*point 17*/
string Office::getRoom(int j) { return roomList[j]->roomName; }

void Office::setCorpName(char* inpName) {
    corpName = new char(sizeof(strlen(inpName)));
    corpName = inpName;
};
//void Office::printCorpName();
string Office::getCorpName() { return corpName; }

/*point 13*/
Office::~Office() {
    cout << "Destructor for: " << corpName;
    for (int j(0); j < size; j++)
        delete roomList[j];
};