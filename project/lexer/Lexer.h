//
// Created by inbar on 12/26/2019.
//

#ifndef PROJECT1_EXTRAFUNCTIONS_H
#define PROJECT1_EXTRAFUNCTIONS_H
#include <vector>
#include <string>
#include <fstream>
using namespace std;
class Lexer {
public:
    Lexer()= default;
    virtual ~Lexer()= default;
    vector<string> Tokenize(string file_name);
private:
    vector<string> AddVectors(vector<string> a, vector<string> b);
    vector<string> Split(string str, string splitBy, bool del);
    vector<string> SplitAll(string str, vector<pair<string, int>> splitBy);
    string DeleteStr(string str, string del);
    string Sub(string str, int start, int finish);
};


#endif //PROJECT1_EXTRAFUNCTIONS_H
