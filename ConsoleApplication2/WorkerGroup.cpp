#include "WorkerGroup.h"
WorkerGroup::WorkerGroup(vector<Worker> workers, bool status, string type) {
    this->workers = workers;
    this->status = status;
    char typeChar{ type[0] };
    this->type = typeChar;
    for (int i = 0; i < workers.size(); i++) {
        price += workers[i].getSalary();
    }
}
WorkerGroup::WorkerGroup() {}
vector<Worker> WorkerGroup::getWorkerGroup() { return workers; }
void WorkerGroup::setGroupStatus(bool status_) { status = status_; }
void WorkerGroup::setGroupType(char type_) { type = type_; }

int WorkerGroup::getPrice() { return price; }

bool WorkerGroup::getStatus() { return status; }
string WorkerGroup::getType() { return type; }
void WorkerGroup::print() {
    cout << "\nGroup status: " << status;
    cout << "\nPrice: " << price;
    cout << "\nGroup type: " << type;
    cout << "\nWorkers: ";
    for (int i = 0; i < workers.size(); i++) {
        cout << "\n" << workers[i].getName() << " " << workers[i].getSecondName();
    }
}