#pragma once
#include "Person.h"
#include "WorkToFiles.h"

class Worker : public Person {
    int id;
    bool status = 1;
    int salary;

public:
    static int max_id;
    Worker(string name, string lastName, int salary);

    Worker();

    bool getStatus();
    int getSalary();

    int getId();

    void setStatus(bool status);
    void print();
};


