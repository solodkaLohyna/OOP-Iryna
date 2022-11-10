#include "Area.h"
using namespace AreaSpace;

void Area::printA() {
    cout << "\nStreet: " << street << " number: " << numArea << " X: " << size_x
        << " Y: " << size_y;
}
Area::Area() {}
/*point 13*/
Area::~Area() { cout << "\ndtor for area"; };