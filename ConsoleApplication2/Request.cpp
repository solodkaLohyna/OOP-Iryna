#include "Request.h"
Request::Request(Householder hh, Dispetcher disp = Dispetcher()) {
    hholder = hh;
    dispetcher = disp;
}
Request::Request(const Request& newReq)
    : hholder(newReq.hholder), dispetcher(newReq.dispetcher),
    typeOfWork(newReq.typeOfWork), size(newReq.size), time(newReq.time) {}
Request::Request() {}

void Request::setDispetcher(Dispetcher& disp) { dispetcher = disp; }
void Request::setHouseholder(Householder& hh) { hholder = hh; }

Dispetcher Request::getDispetcher() { return dispetcher; }
Householder Request::getHouseholder() { return hholder; }

void Request::addInformation(string work_r, string size_r, float time_r) {
    typeOfWork = work_r;
    size = size_r;
    time = time_r;

}

string Request::getWork() { return typeOfWork; }
string Request::getSize() { return size; }
float Request::getTime() { return time; }

void Request::print() {
    cout << "\nThe householder: " << hholder.getName() << " "
        << hholder.getSecondName();
    if (dispetcher.getDispetcherName().length() <= 0)
        cout << "\nDispetcher isn't added";
    else
        cout << "\nThe dispetcher: " << dispetcher.getDispetcherName();
    cout << "\nWork: " << typeOfWork;
    cout << "\nSize: " << size;
    cout << "\nTime: " << time;
}