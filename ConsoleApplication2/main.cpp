#include "PublicUtility.h"
#include <cstdio>
#include <exception>
#include <fstream>
#include <iostream>
#include <ostream>
#include <stdio.h>
#include <string>
#include <sys/stat.h>
#include <vector>

bool isEmpty(string filename);

struct emptynessOfFiles {
    bool emptyHouseholders = isEmpty(householdersFile);
    bool emptyRequests = isEmpty(requestsFile);
    bool emptyDispetchers = isEmpty(dispetchersFile);
    bool emptyWorkers = isEmpty(workersFile);
    bool emptyBrigades = isEmpty(brigadesFile);
    bool emptyPlan = isEmpty(plansFile);
};
emptynessOfFiles statusContainer;

void dispetcherMenu(PublicUtility& pub);

bool isEmpty(string filename) {
    ofstream openToCreate(filename, ios::out | ios::app);
    openToCreate.close();

    ifstream isEmpty(filename, ios::ate | ios::binary);
    size_t size = isEmpty.tellg();
    // cout << size;
    isEmpty.close();

    if (size <= 0)
        return true;

    return false;
}

/*point 11, 12*/
void count(PublicUtility pub) {
    int k = pub.getReqCount();
    cout << "\nNow, there are " << k << " request(-s)\n";
    ofstream set_req("count.txt", ios::trunc);
    set_req.write((char*)&k, sizeof(int));
    set_req.close();
}

/*point 21*/
void count(PublicUtility* obj) {
    if (isEmpty("count.txt") == true) {
        cout << "There are 0 request(-s)\n\n";
    }
    else {
        ifstream get_req("count.txt", ios::in);
        int k;
        get_req.read((char*)&k, sizeof(int));
        get_req.close();
        obj->setCount(k);

        ofstream count_req("count.txt");
        int c = obj->getReqCount();
        count_req.write((char*)&c, sizeof(int));
        cout << "There are " << obj->getReqCount() << " request(-s)\n\n";
    }
}

void streamDispetcher(vector<Dispetcher>& dispet) {
    WorkToFiles writeDsp;
    int dispetCount = dispet.size();
    ofstream streamDispetchers(dispetchersFile, ios::binary);
    if (!streamDispetchers) {
        cout << "Error in openning file!";
        return;
    }
    writeDsp.notStrToFile(dispetCount, streamDispetchers);

    for (int i = 0; i < dispetCount; i++) {
        string nameDsp = dispet.at(i).getDispetcherName(),
            secndNameDsp = dispet.at(i).getDispetcherSecdName();
        writeDsp.writeStrFile(nameDsp, streamDispetchers);
        writeDsp.writeStrFile(secndNameDsp, streamDispetchers);
    }
    streamDispetchers.close();
}

void addDispetcher(PublicUtility& pub) {
    char name[15], secondName[15];
    cout << "Enter the dispetcher's first name and second name: ";
    cin >> name;
    cin >> secondName;
    Dispetcher dispetcher(name, secondName);
    pub.addDispetcher(dispetcher);
}

void streamHouseholder(Householder& householder) {
    WorkToFiles writeHh;
    ofstream streamHouseholders(householdersFile, ios::binary | ios::app);
    if (!streamHouseholders) {
        cout << "Error in openning file!";
        return;
    }
    string nameHh = householder.getName(),
        secondNameHh = householder.getSecondName();
    writeHh.writeStrFile(nameHh, streamHouseholders);
    writeHh.writeStrFile(secondNameHh, streamHouseholders);

    streamHouseholders.close();
}

Householder addHouseholder(PublicUtility& pub) {
    char name[15], secondName[15];
    cout << "\nHi! Please, enter your first name and second name: ";
    cin >> name;
    cin >> secondName;
    Householder householder(name, secondName);
    pub.addHouseholder(householder);
    streamHouseholder(householder);

    return householder;
}

void streamWorkers(vector<Worker>& workr) {
    WorkToFiles writeWorkers;
    int workerCount = workr.size();
    ofstream streamWrks(workersFile, ios::binary);
    writeWorkers.notStrToFile(workerCount, streamWrks);

    if (!streamWrks) {
        cout << "Error in openning file!";
        return;
    }

    string name, secondName;
    int salary;
    bool status;

    for (int i = 0; i < workerCount; i++) {
        name = workr.at(i).getName();
        secondName = workr.at(i).getSecondName();
        salary = workr.at(i).getSalary();
        status = workr.at(i).getStatus();

        writeWorkers.writeStrFile(name, streamWrks);
        writeWorkers.writeStrFile(secondName, streamWrks);
        writeWorkers.notStrToFile(salary, streamWrks);
        writeWorkers.notStrToFile(status, streamWrks);
    }
    streamWrks.close();
}

void addWorker(PublicUtility& pub) {
    char name[15], secondName[15];
    int salary;
    cout << "Enter the worker's first name and second name: ";
    cin >> name;
    cin >> secondName;
    cout << "Enter the worker's salary: ";
    cin >> salary;
    Worker worker(name, secondName, salary);
    pub.addWorker(worker);
}

void streamRequest(Request& request) {
    WorkToFiles writeReq;
    ofstream streamRequest(requestsFile, ios::binary | ios::app);

    if (!streamRequest) {
        cout << "Error in openning file!";
        return;
    }

    string work = request.getWork(), size = request.getSize();
    float time = request.getTime();

    writeReq.writeStrFile(work, streamRequest);
    writeReq.writeStrFile(size, streamRequest);
    writeReq.notStrToFile(time, streamRequest);

    streamRequest.close();
}

void createRequest(PublicUtility& pub) {
    Request request(addHouseholder(pub));

    string work, size;
    float time;
    cout << "Thank you! Let's start create request \n\nEnter type of work: ";
    cin.ignore(32767, '\n');
    getline(cin, work);
    cout << "Enter size: ";
    getline(cin, size);
    cout << "Enter time: ";
    cin >> time;
    request.addInformation(work, size, time);
    request.print();
    pub.addRequest(request);

    unsigned int c = pub.getReqCount();
    c++;
    pub.setCount(c);
    streamRequest(request);
}

void streamPlan(PublicUtility& pub) {
    WorkToFiles writePlan;
    ofstream streamPlan(plansFile, ios::binary);

    if (!streamPlan) {
        cout << "Error in openning file!";
        return;
    }
    string name, secondName, type;
    int salary;
    bool status;
    string work, size;
    float time;

    int count = pub.getPlans().size();
    writePlan.notStrToFile(count, streamPlan);

    for (int j = 0; j < count; j++) {
        Plan planTemp = pub.getPlans().at(j);
        name = planTemp.getRequestPlan().getHouseholder().getName();
        secondName = planTemp.getRequestPlan().getHouseholder().getSecondName();
        work = planTemp.getRequestPlan().getWork();
        size = planTemp.getRequestPlan().getSize();
        time = planTemp.getRequestPlan().getTime();

        writePlan.writeStrFile(name, streamPlan);
        writePlan.writeStrFile(secondName, streamPlan);
        writePlan.writeStrFile(work, streamPlan);
        writePlan.writeStrFile(size, streamPlan);
        writePlan.notStrToFile(time, streamPlan);

        int workersCount = planTemp.getWorkerGroupPlan().getWorkerGroup().size();
        writePlan.notStrToFile(workersCount, streamPlan);
        for (int i = 0; i < workersCount; i++) {
            name = planTemp.getWorkerGroupPlan().getWorkerGroup().at(i).getName();
            secondName =
                planTemp.getWorkerGroupPlan().getWorkerGroup().at(i).getSecondName();
            salary = planTemp.getWorkerGroupPlan().getWorkerGroup().at(i).getSalary();
            status = planTemp.getWorkerGroupPlan().getWorkerGroup().at(i).getStatus();

            writePlan.writeStrFile(name, streamPlan);
            writePlan.writeStrFile(secondName, streamPlan);
            writePlan.notStrToFile(salary, streamPlan);
            writePlan.notStrToFile(status, streamPlan);
        }
        type = planTemp.getWorkerGroupPlan().getType();
        writePlan.writeStrFile(type, streamPlan);
    }
}

WorkerGroup chooseBrigade(PublicUtility& pub) {
    cout << "\nChoose brigade to add to plan: ";
    int brigadeNumber;
    cin >> brigadeNumber;
    cout << "point 1\n";
    WorkerGroup groupTemp =
        pub.getCurrentDispetcher().setGroupToPlan(brigadeNumber - 1);
    cout << "point 1.1\n";
    return groupTemp;
}

void acceptRequest(PublicUtility& pub) {
    if (pub.getRequest().size() == 0) {
        cout << "\nThere are no requests yet\n";
    }
    else {
        Dispetcher currentDispetcher = pub.getCurrentDispetcher();
        if (currentDispetcher.isSomeBrigadeFree()) {
            cout << "\nThere are some free brigades\n";
            currentDispetcher.printFreeBrigades();
        }
        cout << endl;
        pub.printRequests();
        cout << pub.getCurrentDispetcher().getDispetcherName()
            << ", choose a request: ";

        int requestNumber;
        cin >> requestNumber;
        pub.getRequest().at(requestNumber - 1).setDispetcher(currentDispetcher);
        cout << "point 2\n";
        pub.getRequest().at(requestNumber - 1).print();

        cout << "point 3\n";
        cout << "point 4\n";
        WorkerGroup groupTemp = chooseBrigade(pub);
        cout << "point 4.1\n";
        Request reqTemp(pub.getRequest().at(requestNumber - 1));

        cout << "point 5 \n";
        Plan currentPlan(reqTemp, groupTemp);
        pub.addPlans(currentPlan);
        streamPlan(pub);
    }
}

void refuseRequest(PublicUtility& pub) {
    if (pub.getRequest().size() == 0) {
        cout << "\nThere are no requests yet\n";
    }
    else {
        cout << endl;
        pub.printRequests();
        cout << pub.getCurrentDispetcher().getDispetcherName()
            << ", choose a request: ";
        int requestNumber;
        cin >> requestNumber;
        pub.deleteRequest(requestNumber);
    }
}

void streamBrigade(PublicUtility& pub) {
    WorkToFiles writeBrigades;
    ofstream streamBrigades(brigadesFile, ios::binary);
    if (!streamBrigades) {
        cout << "Error in openning file!";
        return;
    }

    int workersCount, brigadeCount = pub.getCurrentDispetcher().getBrCount();
    string type;
    bool status;
    int position;

    writeBrigades.notStrToFile(brigadeCount, streamBrigades);
    for (int i = 0; i < pub.getDispetchers().size(); i++) {
        cout << "point 1\n";
        pub.setCurrentDispetcher(&pub.getDispetchers().at(i));
        if (pub.getCurrentDispetcher().getGroups().empty() == true)
            continue;
        cout << "point 2\n";
        pub.setDispetcherPosition(i);
        for (int k = 0; k < pub.getCurrentDispetcher().getGroups().size(); k++) {
            Dispetcher dispTemp = pub.getCurrentDispetcher();
            cout << "point 3\n";
            workersCount = dispTemp.getGroup(k).getWorkerGroup().size();
            cout << "point 4\n";
            position = pub.getDisptecherPosition();
            cout << "point 5\n";
            writeBrigades.notStrToFile(workersCount, streamBrigades);
            for (int j = 0; j < workersCount; j++) {
                int id = dispTemp.getGroups().at(k).getWorkerGroup().at(j).getId();
                writeBrigades.notStrToFile(id, streamBrigades);
            }
            status = dispTemp.getGroupStatus(k);
            type = dispTemp.getGroupType(k);
            writeBrigades.notStrToFile(status, streamBrigades);
            writeBrigades.writeStrFile(type, streamBrigades);
            writeBrigades.notStrToFile(position, streamBrigades);
        }
    }
    streamBrigades.close();
}

void createBrigade(PublicUtility& pub) {
    cout << "\nDisplaying all workers...";
    if (pub.getWorkers().size() == 0) {
        cout << "\nThere are no workers\n";
        return;
    }
    pub.printFreeWorkers();
    int workersCount = 0, number;
    cout << "\nEnter number of the workers(at least 5): ";
    while (workersCount < 5) {
        cin >> workersCount;
        cout << "\nStart choosing workers: ";
        vector<Worker> brigade;
        for (int i = 0; i < workersCount; i++) {
            cin >> number;
            brigade.push_back(pub.getWorkers().at(number - 1));
            pub.getWorkers()
                .at(number - 1)
                .setStatus(false); 
        }
        string type;
        while (type.size() != 1) {
            cout << "\nEnter type of the brigade: ";
            cin >> type;
        }
        bool status = true;
        WorkerGroup group(brigade, status, type);
        pub.getCurrentDispetcher().addGroup(group);
    }
    streamBrigade(pub);
}

void printBrigades(PublicUtility& pub) {
    pub.getCurrentDispetcher().printBrigades();
}

void printFriendPlan(Plan plan) {
    plan.request.print();
    plan.group.print();
}

void printPlan(PublicUtility& pub) {
    if (pub.getPlans().size() == 0)
        cout << "\nThere are no plans!";
    else {
        cout << "\nThe plan of work: ";
        for (int i = 0; i < pub.getPlans().size(); i++)
            printFriendPlan(pub.getPlans().at(i));
        cout << endl;
    }
}

void logInAsDispetcher(PublicUtility& pub) {
    int dispetcherNumber;
    cout << "\nHi, dispetcher! Enter as ";
    pub.printDispetchers();

    cout << "Input number: ";
    cin >> dispetcherNumber;
    pub.setCurrentDispetcher(&pub.getDispetchers().at(dispetcherNumber - 1));
    pub.setDispetcherPosition(dispetcherNumber - 1);
    dispetcherMenu(pub);
}

void dispetcherMenu(PublicUtility& pub) {
    int option;
    cout << "\nChoose your option: \n0. Come back to the home page\n1. Print all "
        "requests\n2. Accept request\n3. "
        "Create brigade\n4. Print brigades\n5. Refuse request\n6. Print "
        "plans: ";
    cin >> option;

    switch (option) {
    case 0:
        return;
        break;
    case 1:
        pub.printRequests();
        break;
    case 2:
        acceptRequest(pub);
        break;
    case 3:
        createBrigade(pub);
        break;
    case 4:
        printBrigades(pub);
        break;
    case 5:
        refuseRequest(pub);
        break;
    case 6:
        printPlan(pub);
        break;
    }
    dispetcherMenu(pub);
}

unsigned int PublicUtility::requestCount = 0;
int PublicUtility::dispetcherPosition = 0;
int Plan::id = 0;

void countt(Office*& office) {
    cout << "\n\nList of rooms: \n";
    for (int i = 0; i < office->getSize(); i++)
        cout << i + 1 << ". " << office->getRoom(i) << endl;
}

void adjustOffice() {
    double x, y;
    int numberOfBuilding, floorNumber;
    string streetName, buildingType;

    cout << "\nLet's adjust out office!";
    cout << "\nEnter length of one floor: ";
    cin >> x;
    cout << "Enter width of one floor: ";
    cin >> y;
    cout << "Enter number of floor: ";
    cin >> floorNumber;
    cout << "Enter type of building: ";
    cin >> buildingType;
    cout << "Enter street name: ";
    cin >> streetName;
    cout << "Enter building number: ";
    cin >> numberOfBuilding;

    cout << endl;
    Office* office =
        new Office(x, y, numberOfBuilding, streetName, buildingType, floorNumber);
    cout << endl;

    vector<string> rooms;
    int num;
    cout << "Enter number of the rooms: ";
    cin >> num;
    cout << endl;

    string room;
    for (int i = 0; i < num; i++) {
        cout << "Enter room " << i + 1 << ": ";
        cin >> room;
        rooms.push_back(room);
        office->add(rooms.at(i));
    }

    countt(office);
}

void loadDispetchers(PublicUtility& pub) {
    WorkToFiles readDsp;
    int dispetCount;
    string name, secondName;

    ifstream streamDsp(dispetchersFile, ios::binary);
    dispetCount = readDsp.notStrFromFile<int>(streamDsp);

    for (int i = 0; i < dispetCount; i++) {
        name = readDsp.readStrFile(streamDsp);
        secondName = readDsp.readStrFile(streamDsp);
        Dispetcher dispTemp(name, secondName);
        pub.addDispetcher(dispTemp);
    }

    streamDsp.close();
}

void loadWorkers(PublicUtility& pub) {
    WorkToFiles readWrks;
    int workerCount, salary;
    string name, secondName;
    bool status;

    ifstream streamWorkers(workersFile, ios::binary);
    workerCount = readWrks.notStrFromFile<int>(streamWorkers);

    for (int i = 0; i < workerCount; i++) {
        name = readWrks.readStrFile(streamWorkers);
        secondName = readWrks.readStrFile(streamWorkers);
        salary = readWrks.notStrFromFile<int>(streamWorkers);
        status = readWrks.notStrFromFile<bool>(streamWorkers);
        Worker workerTemp(name, secondName, salary);
        workerTemp.setStatus(status);
        pub.addWorker(workerTemp);
    }

    streamWorkers.close();
}

void loadRequests(PublicUtility& pub) {
    WorkToFiles readReq;
    unsigned int number = pub.getReqCount();
    string work, size;
    float time;


    ifstream streamReq(requestsFile, ios::binary);
    for (int i = 0; i < number; i++) {
        work = readReq.readStrFile(streamReq);
        size = readReq.readStrFile(streamReq);
        time = readReq.notStrFromFile<float>(streamReq);
        Request reqTemp;
        reqTemp.addInformation(work, size, time);
        reqTemp.setHouseholder(pub.getHouseholder().at(i));
        pub.addRequest(reqTemp);
    }
    streamReq.close();
}

void loadHouseholder(PublicUtility& pub) {
    WorkToFiles readHh;
    unsigned int number = pub.getReqCount();
    string name, secondName;

    ifstream streamHh(householdersFile, ios::binary);
    for (int i = 0; i < number; i++) {
        name = readHh.readStrFile(streamHh);
        secondName = readHh.readStrFile(streamHh);
        Householder hh(name, secondName);
        pub.addHouseholder(hh);
    }
    streamHh.close();
    loadRequests(pub);
}

void loadBrigades(PublicUtility& pub) {
    WorkToFiles readBrigades;
    int workersNum, id, pos;
    bool status;
    string type;

    ifstream streamBrig(brigadesFile, ios::binary);

    int count = readBrigades.notStrFromFile<int>(streamBrig);


    for (int k = 0; k < count; k++) {
        vector<Worker> workersTemp;
        workersNum = readBrigades.notStrFromFile<int>(streamBrig);
        for (int i = 0; i < workersNum; i++) {
            id = readBrigades.notStrFromFile<int>(streamBrig);
            workersTemp.push_back(pub.getWorkers().at(id - 1));
        }
        status = readBrigades.notStrFromFile<bool>(streamBrig);
        type = readBrigades.readStrFile(streamBrig);
        int position = readBrigades.notStrFromFile<int>(streamBrig);

        WorkerGroup groupTemp(workersTemp, status, type);
        pub.getDispetchers().at(position).addGroup(groupTemp);
    }
    streamBrig.close();
}

void loadPlans(PublicUtility& pub) {
    WorkToFiles readPlans;
    string name, secondName, work, size, type;
    bool status;
    int salary;
    float time;

    ifstream streamPlans(plansFile, ios::binary);
    int planCount = readPlans.notStrFromFile<int>(streamPlans);
    for (int i = 0; i < planCount; i++) {
        name = readPlans.readStrFile(streamPlans);
        secondName = readPlans.readStrFile(streamPlans);
        work = readPlans.readStrFile(streamPlans);
        size = readPlans.readStrFile(streamPlans);
        time = readPlans.notStrFromFile<float>(streamPlans);
        Householder hhTemp(name, secondName);
        Request reqTemp(hhTemp);
        reqTemp.addInformation(work, size, time);

        vector<Worker> workers;
        workers.resize(0);
        int workersCount = readPlans.notStrFromFile<int>(streamPlans);
        for (int j = 0; j < workersCount; j++) {
            name = readPlans.readStrFile(streamPlans);
            secondName = readPlans.readStrFile(streamPlans);
            salary = readPlans.notStrFromFile<int>(streamPlans);
            status = readPlans.notStrFromFile<bool>(streamPlans);
            Worker workerTemp(name, secondName, salary);
            workerTemp.setStatus(status);
            workers.push_back(workerTemp);
        }
        type = readPlans.readStrFile(streamPlans);
        WorkerGroup groupTemp(workers, false, type);

        Plan planTemp(reqTemp, groupTemp);
        pub.addPlans(planTemp);
    }
}

void loadData(PublicUtility& pub) {
    // statusContainer.emptyHouseholders
    if (statusContainer.emptyHouseholders != true)
        loadHouseholder(pub);
    // cout << "1\n";
    if (statusContainer.emptyDispetchers != true)
        loadDispetchers(pub);
    // cout << "2\n";
    if (statusContainer.emptyWorkers != true)
        loadWorkers(pub);
    // cout << "3\n";
    if (statusContainer.emptyBrigades != true)
        loadBrigades(pub);

    if (statusContainer.emptyPlan != true)
        loadPlans(pub);
}

int Worker::max_id = 0;
int Dispetcher::brigadeCount = 0;

int main() {
    // cout << "1\n";
    PublicUtility pub;
    count(&pub);
    // cout << "2\n";

    // test(pub);
    // readtest();
    loadData(pub);
    // cout << "4\n";

    // pub.printFreeWorkers();
    cout
        << "---You are logged in to the 'Letychiv Housing and Communal Services' "
        "system!---";
    int opt = -1;
    while (opt != 0) {
        cout << "\n\nChoose your option: \n1. Create request\n"
            "2. Add dispetcher/-s\n3. "
            "Add worker/-s\n4. Enter as dispetcher\n5. Adjust office: ";
        cin >> opt;
        switch (opt) {
        case 1:
            count(&pub);
            createRequest(pub);
            count(pub);
            break;
        case 2:
            int dispetchers_count;
            cout << "\nEnter the number of dispetchers: ";
            cin >> dispetchers_count;

            for (int i = 0; i < dispetchers_count; i++)
                addDispetcher(pub);

            streamDispetcher(pub.getDispetchers());
            break;
        case 3:
            int workers_count;
            cout << "\nEnter the number of workers: ";
            cin >> workers_count;

            for (int i = 0; i < workers_count; i++)
                addWorker(pub);
            break;

        case 4:
            if (pub.getDispetchers().size() == 0) {
                cout << "\nThere are no dispetchers yet!";
            }
            else {
                logInAsDispetcher(pub);
            }
            break;
        case 5:
            adjustOffice();
            break;
        }
    }
    streamWorkers(pub.getWorkers());
}
