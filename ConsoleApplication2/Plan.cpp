#include "Plan.h"
Plan::Plan(Request req, WorkerGroup workGroup) {
    request = req;
    group = workGroup;
    id++;
}
Plan::Plan() {}

void Plan::setRequest(Request req) { request = req; }
void Plan::setGroup(WorkerGroup workGroup) { group = workGroup; }

Request Plan::getRequestPlan() { return request; }
WorkerGroup Plan::getWorkerGroupPlan() { return group; }