#pragma once
#include "Office.h"
#include "Plan.h"
#include <algorithm>
#include <iostream>
#include <vector>
#define dispetchersFile "dispetchers.bin"
#define householdersFile "householders.bin"
#define requestsFile "requests.bin"
#define workersFile "workers.bin"
#define brigadesFile "brigades.bin"
#define plansFile "plans.bin"
using namespace std;

class PublicUtility {
private:
    vector<Dispetcher> dispetchers{};
    vector<Householder> householders{};
    vector<Request> request{};
    vector<Worker> workers;
    vector<Plan> plans{};

    Dispetcher* currentDispetcher;
    static int dispetcherPosition;
    static unsigned int requestCount;

public:
    PublicUtility();

    vector<Dispetcher>& getDispetchers();
    vector<Householder>& getHouseholder();
    vector<Request>& getRequest();
    vector<Worker>& getWorkers();
    vector<Plan>& getPlans();
    Dispetcher& getCurrentDispetcher();
    unsigned int getReqCount();
    int getDisptecherPosition();

    void addDispetcher(Dispetcher disp);
    void addHouseholder(Householder householder);
    void addRequest(Request req);
    void addWorker(Worker worker);
    void addPlans(Plan plan);

    void setCurrentDispetcher(Dispetcher* dispetcher);
    void setCount(unsigned int count);
    void setDispetcherPosition(int position);

    void printWorkers();

    void printFreeWorkers();

    void printDispetchers();

    void printHouseholder();

    void printRequests();

    // void printPlans() {
    //   cout << "List of plan of work: \n";
    //   if (plans.size() == 0)
    //     cout << "There are no plans!";
    //   else {
    //     for (int i = 0; i < plans.size(); i++) {
    //       cout << i + 1 << ". " <<
    //     }
    //   }
    // }

    void deleteRequest(int number);

    void eraseHouseholder(int number);

    ~PublicUtility();
};


