#pragma once
#include "Person.h"
#include <string>

class Householder : private Person {
    // Request req;
public:
    Householder(string name, string secondName);

    Householder();
    string getName();
    string getSecondName();


    ~Householder();
};


