#pragma once
#include "Person.h"
#include "WorkerGroup.h"
#include <fstream>
#include <type_traits>
#include <vector>

class Dispetcher : private Person {
    // string name;
    // string secondName;
    vector<WorkerGroup> groups;
    static int brigadeCount;

public:
    /*point 4*/
    Dispetcher(string, string);
    // Dispetcher(const Dispetcher &disp) : Person(name, sec), groups(disp.groups)
    // {}
    Dispetcher() {}

    // void setName(char *inpName) { this->name = inpName; }

    void addGroup(WorkerGroup& group);

    string getDispetcherName();
    string getDispetcherSecdName();
    int getBrCount();

    bool getGroupStatus(int n);
    string getGroupType(int n);
    vector<WorkerGroup> getGroups();
    WorkerGroup getGroup(int n);

    WorkerGroup setGroupToPlan(int n);

    void printBrigades();

    void printFreeBrigades();

    bool isSomeBrigadeFree();

    ~Dispetcher();
};

