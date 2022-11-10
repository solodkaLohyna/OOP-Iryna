#pragma once
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

/*point 18*/

class WorkToFiles {
    template <class T>
    static void writeNotStr(const T& someVariable, ostream& f) {
        f.write((char*)&someVariable, sizeof(T));
    }

    static void writeStr(const string& string, ostream& f) {
        size_t len = string.length();
        f.write((char*)&len, sizeof(size_t));
        f.write(string.data(), len);
        // cout << "success";
    }

    template <class T> static T readNotStr(istream& f) {
        T newVariable;
        f.read((char*)&newVariable, sizeof(T));
        return newVariable;
    }

    static string readStr(istream& f) {
        size_t l;
        string strTemp;

        f.read((char*)&l, sizeof(size_t));
        char* str = new char[l + 1];
        f.read(str, l);
        str[l] = 0;
        strTemp = str;
        // cout << work;
        delete[] str;
        // cout << "success\n";
        return strTemp;
    }

public:
    WorkToFiles();

    template <class T> void notStrToFile(T& someVariabel, ostream& f) const;

    void writeStrFile(string& s, ostream& f) const;

    template <class T> T notStrFromFile(istream& f);

    string readStrFile(istream& f) ;
};

