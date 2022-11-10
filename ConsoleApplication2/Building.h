#pragma once
#include <iostream>
#pragma once
/*point 10*/
using namespace std;

namespace BuildingSpace {

    class Building {
    private:
        string type;
        int floors;

    public:
        Building(string type_b, int floors_b) : type(type_b), floors(floors_b) {
            /*point 13*/
            cout << "Constructor for building\n";
        }
        void printB();
        Building();
        /*point 13*/
        ~Building();
    };
} // namespace BuildingSpace
