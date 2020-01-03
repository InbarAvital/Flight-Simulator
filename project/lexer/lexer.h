//
// Created by inbar on 12/26/2019.
//

#ifndef PROJECT1_EXTRAFUNCTIONS_H
#define PROJECT1_EXTRAFUNCTIONS_H
#include <vector>
#include <string>
#include <fstream>
using namespace std;
vector<string> addVectors(vector<string> a, vector<string> b);
vector<string> split(string str, string splitBy, bool del);
vector<string> splitAll(string str, vector<pair<string, int>> splitBy);
vector<string> lexer(string file_name);
string sub(string str, int start, int finish);
class extraFunctions {
};


#endif //PROJECT1_EXTRAFUNCTIONS_H
