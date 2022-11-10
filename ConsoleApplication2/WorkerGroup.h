#pragma once
#include "Worker.h"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

class WorkerGroup {
    vector<Worker> workers;
    bool status;
    string type;
    int price;

public:
    WorkerGroup(vector<Worker> workers, bool status, string type);
    WorkerGroup();
    vector<Worker> getWorkerGroup();
    void setGroupStatus(bool status_);
    void setGroupType(char type_);

    int getPrice();

    bool getStatus();
    string getType();
    void print();
};


