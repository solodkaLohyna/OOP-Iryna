#include "WorkToFiles.h"
WorkToFiles::WorkToFiles() {}

template <class T> void WorkToFiles::notStrToFile(T& someVariabel, ostream& f) const {
    writeNotStr(someVariabel, f);
}

void WorkToFiles::writeStrFile(string& s, ostream& f) const { writeStr(s, f); }

template <class T> T WorkToFiles::notStrFromFile(istream& f) { return readNotStr<T>(f); }

string WorkToFiles::readStrFile(istream& f) { return readStr(f); }