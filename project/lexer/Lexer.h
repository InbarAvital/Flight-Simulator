//
// Created by inbar on 12/26/2019.
//

#ifndef PROJECT1_EXTRAFUNCTIONS_H
#define PROJECT1_EXTRAFUNCTIONS_H
#include <vector>
#include <string>
#include <fstream>
using namespace std;
// This class uses the singleton design pattern and has only one instance.
class Lexer {
 public:
  // Deletes the single instance of this class.
  virtual ~Lexer();

  // Input: file_name - The name of the file.
  // Output: The tokens in this file (commands and parameters).
  vector<string> Tokenize(string file_name);

  // Output: The single instance of this class.
  static Lexer *GetInstance();

 private:
  Lexer() = default;
  static Lexer *instance;
  vector<string> AddVectors(vector<string> a, vector<string> b);
  vector<string> Split(string str, string splitBy, bool del);
  vector<string> SplitAll(string str, vector<pair<string, int>> splitBy);
  string DeleteStr(string str, string del);
  string Sub(string str, int start, int finish);
};


#endif //PROJECT1_EXTRAFUNCTIONS_H
