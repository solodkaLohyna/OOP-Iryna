#pragma once
// #include "PublicUtility.h"
#include "Dispetcher.h"
#include "Householder.h"
#include <iostream>
#include <string>

using namespace std;

#pragma once
class Request {
    Householder hholder;
    Dispetcher dispetcher;
    string typeOfWork;
    string size;
    float time;

public:
    Request(Householder hh, Dispetcher disp = Dispetcher());
    Request(const Request& newReq);
    Request();

    void setDispetcher(Dispetcher& disp);
    void setHouseholder(Householder& hh);

    Dispetcher getDispetcher();
    Householder getHouseholder();

    void addInformation(string work_r, string size_r, float time_r);

    string getWork();
    string getSize();
    float getTime();

    void print();
};

