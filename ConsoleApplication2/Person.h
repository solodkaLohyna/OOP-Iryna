#pragma once
#include <cstring>
#include <iostream>

#pragma once
using namespace std;

class Person {
protected:
    string firstName;
    string secondName;

public:
    Person(string firstName, string lastName);

    string getName();
    string getSecondName();

    Person();
};