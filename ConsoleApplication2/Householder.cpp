#include "Householder.h"

Householder::Householder(string name, string secondName) {
    this->firstName = name;
    this->secondName = secondName;
}

Householder::Householder() {}
string Householder::getName() { return firstName; }
string Householder::getSecondName() { return secondName; }

Householder::~Householder() {}