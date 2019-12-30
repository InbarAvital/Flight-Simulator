//
// Created by inbar on 12/26/2019.
//

#ifndef PROJECT1_EXTRAFUNCTIONS_H
#define PROJECT1_EXTRAFUNCTIONS_H
#include <list>
#include <string>
#include <fstream>
using namespace std;
list<string> split(string str, string splitBy);
list<string> splitAll(string str, list<string> splitBy);
list<string> addLists(list<string> a, list<string> b);
list<string> lexer(string file_name);
class extraFunctions {
};


#endif //PROJECT1_EXTRAFUNCTIONS_H
