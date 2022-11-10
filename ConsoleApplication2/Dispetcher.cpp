#include "Dispetcher.h"

Dispetcher::Dispetcher(string firstName, string secondName) {
    this->firstName = firstName;
    this->secondName = secondName;
}

void Dispetcher::addGroup(WorkerGroup& group) {
    groups.push_back(group);
    brigadeCount++;
}

string Dispetcher::getDispetcherName() { return getName(); }
string Dispetcher::getDispetcherSecdName() { return getSecondName(); }
int Dispetcher::getBrCount() { return brigadeCount; }

bool Dispetcher::getGroupStatus(int n) { return groups.at(n).getStatus(); }
string Dispetcher::getGroupType(int n) { return groups.at(n).getType(); }
vector<WorkerGroup> Dispetcher::getGroups() { return groups; }
WorkerGroup Dispetcher::getGroup(int n) { return groups.at(n); }

WorkerGroup Dispetcher::setGroupToPlan(int n) { return groups.at(n); }

void Dispetcher::printBrigades() {
    cout << "\nList of brigades:\n";
    if (groups.size() == 0) {
        cout << "\nThere are no brigades\n";
    }
    else {
        for (int i = 0; i < groups.size(); i++) {
            cout << "Brigade " << i + 1 << ", status: " << getGroupStatus(i)
                << ", type: " << getGroupType(i)
                << ", price: " << groups[i].getPrice() << endl;
        }
    }
}

void Dispetcher::printFreeBrigades() {
    cout << "\nList of free brigades:\n";
    if (groups.size() == 0) {
        cout << "\nThere are no brigades\n";
    }
    else {
        for (int i = 0; i < groups.size(); i++) {
            if (getGroupStatus(i) == 1) {
                cout << "Brigade " << i + 1 << ", status: " << getGroupStatus(i)
                    << ", type: " << getGroupType(i)
                    << ", price: " << groups[i].getPrice() << endl;
            }
        }
    }
}

bool Dispetcher::isSomeBrigadeFree() {
    for (int i = 0; i < groups.size(); i++) {
        if (getGroupStatus(i) == 1) {
            return true;
        }
    }
    return false;
}

Dispetcher::~Dispetcher() {}