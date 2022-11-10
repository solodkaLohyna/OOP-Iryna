#pragma once
#include "Request.h"

class Plan {
    Request request;
    WorkerGroup group;
    static int id;
public:
    Plan(Request req, WorkerGroup workGroup);
    Plan();

    void setRequest(Request req);
    void setGroup(WorkerGroup workGroup);

    Request getRequestPlan();
    WorkerGroup getWorkerGroupPlan();

    friend void printFriendPlan(Plan plan);
};


