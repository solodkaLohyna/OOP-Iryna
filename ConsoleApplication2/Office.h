#pragma once
#include "Area.h"
#include "Building.h"
// #include "PublicUtility.h"
#include "Room.h"
#include <string.h>
#include <vector>

#pragma once
/*point 10*/

/*point 12*/
using namespace std;
using namespace BuildingSpace;
using namespace AreaSpace;

class Office : public Building, public Area {
    char* corpName;
    /*חשרעו 23*/
    Room* roomList[20];
    int size;

public:
    /*point 5*/
    /*point 11*/
    /*point 22*/
    Office(double x, double y, int number, string street_o, string type_o,
        int floor_o);

    const int getSize() const;
    const Room** getRoom(int& n) const;

    bool add(const string room);
    /*point 17*/
    string getRoom(int j);

    void setCorpName(char* inpName);
    //void printCorpName();
    string getCorpName();

    /*point 13*/
    ~Office();


    /*point 17*/
    /*point 16*/
    friend void countt(Office& office);
    friend class Room;
};
