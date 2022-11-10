#include "Worker.h"
Worker::Worker(string name, string lastName, int salary)
    : Person(name, lastName), salary(salary) {
    id = ++max_id;
};

Worker::Worker() : id(++max_id) {};

// string getWorkerName() { return name; }
// string getWorkerSeconName(){return secondName;}
bool Worker::getStatus() { return status; }
int Worker::getSalary() { return salary; }

int Worker::getId() { return id; }

void Worker::setStatus(bool status) { this->status = status; }
void Worker::print() {
    cout << "Worker " << id << ": " << firstName << " " << secondName << " " << salary << endl;
}