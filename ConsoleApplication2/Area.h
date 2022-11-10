#pragma once
#include <iostream>
#pragma once
/*point 10*/
using namespace std;

namespace AreaSpace {
    class Area {
    private:
        string street;
        int numArea;
        double size_x;
        double size_y;

    public:
        Area(string streer_a, int num, double sizeX, double sizeY)
            : numArea(num), size_x(sizeX), size_y(sizeY), street(streer_a) {
            /*point 13*/
            cout << "Constructor for area\n";
        }

        void printA();
        Area();
        /*point 13*/
        ~Area();
    };
} // namespace AreaSpace

