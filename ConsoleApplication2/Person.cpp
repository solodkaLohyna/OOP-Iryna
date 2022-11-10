#include "Person.h"
Person::Person(string firstName, string lastName) {
    this->firstName = firstName;
    this->secondName = lastName;
}


string Person::getName() { return firstName; }
string Person::getSecondName() { return secondName; }

Person::Person() {}