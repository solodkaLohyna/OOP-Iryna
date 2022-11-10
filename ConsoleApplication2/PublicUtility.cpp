#include "PublicUtility.h"
PublicUtility::PublicUtility() {}

vector<Dispetcher>& PublicUtility::getDispetchers() { return (dispetchers); }
vector<Householder>& PublicUtility::getHouseholder() { return (householders); }
vector<Request>& PublicUtility::getRequest() { return request; }
vector<Worker>& PublicUtility::getWorkers() { return workers; }
vector<Plan>& PublicUtility::getPlans() { return plans; }
Dispetcher& PublicUtility::getCurrentDispetcher() { return *currentDispetcher; }
unsigned int PublicUtility::getReqCount() { return requestCount; }
int PublicUtility::getDisptecherPosition() { return dispetcherPosition; }

void PublicUtility::addDispetcher(Dispetcher disp) { dispetchers.push_back(disp); }
void PublicUtility::addHouseholder(Householder householder) {
    householders.push_back(householder);
}
void PublicUtility::addRequest(Request req) { request.push_back(req); }
void PublicUtility::addWorker(Worker worker) { workers.push_back(worker); }
void PublicUtility::addPlans(Plan plan) { plans.push_back(plan); }

void PublicUtility::setCurrentDispetcher(Dispetcher* dispetcher) {
    currentDispetcher = dispetcher;
}
void PublicUtility::setCount(unsigned int count) { requestCount = count; }
void PublicUtility::setDispetcherPosition(int position) { dispetcherPosition = position; }

void PublicUtility::printWorkers() {
    cout << "\nList of workers: \n";
    if (workers.size() <= 0) {
        cout << "There are no workers yet";
    }
    else {
        for (int i = 0; i < workers.size(); i++) {
            cout << workers.at(i).getId() << ". " << workers.at(i).getName() << " "
                << workers.at(i).getSecondName() << endl;
        }
    }
}

void PublicUtility::printFreeWorkers() {
    cout << "\nList of free workers: \n";
    if (workers.size() == 0) {
        cout << "\nThere are no workers yet\n";
    }
    else {
        for (int i = 0; i < workers.size(); i++) {
            if (workers.at(i).getStatus() == 1)
                cout << i + 1 << ". " << workers.at(i).getName() << " "
                << workers.at(i).getSecondName() << " "
                << workers.at(i).getSalary() << "UAH" << endl;
        }
    }
}

void PublicUtility::printDispetchers() {
    cout << "\nDispetchers: \n";
    if (dispetchers.size() == 0) {
        cout << "There are no dispetchers yet";
    }
    else {
        for (int i = 0; i < dispetchers.size(); i++) {
            cout << i + 1 << ". " << dispetchers.at(i).getDispetcherName() << " "
                << dispetchers.at(i).getDispetcherSecdName() << ".\n";
        }
    }
}

void PublicUtility::printHouseholder() {
    cout << "\nHouseholders: \n";
    if (householders.size() == 0) {
        cout << "There are no householders yet";
    }
    else {
        for (int i = 0; i < householders.size(); i++) {
            cout << i + 1 << ". " << householders.at(i).getName() << " "
                << householders.at(i).getSecondName() << ".\n";
        }
    }
}

void PublicUtility::printRequests() {
    cout << "\nRequests: \n";
    if (request.size() == 0) {
        cout << "There are no requests yet\n";
    }
    else {
        for (int i = 0; i < request.size(); i++) {
            cout << i + 1 << ". ";
            request.at(i).print();
            cout << endl;
        }
    }
}

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

void PublicUtility::deleteRequest(int number) {
    request.erase(request.begin() + number - 1);
    eraseHouseholder(number);
}

void PublicUtility::eraseHouseholder(int number) {
    householders.erase(householders.begin() + number - 1);
}

PublicUtility::~PublicUtility() { cout << "\ndtor for PU"; }
