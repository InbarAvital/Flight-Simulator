//
// Created by noam on 03/01/2020.
//

#ifndef EX3_EXPRESSIONS_INTERPRETER_H_
#define EX3_EXPRESSIONS_INTERPRETER_H_

#include <string>
#include <list>
#include <deque>
#include <map>
#include "Expression.h"

class Interpreter {
 public:
  Expression *interpret(string str);
  void setVariables(const string& str);

 private:
  static list<string> Split(string str, char c);
  static int GetPrecedence(char op);
  Expression *CalcExp(const deque<string>& output);
  static deque<string> ReadTokens(const list<string>& tokens);
  static bool IsNumber(const string& str);
  static bool IsOperator(const string& str);
  static bool IsVariable(const string& str);
  static string ReadNumber(const string& str);
  string ReadVariable(const string& str);
  static string ReadOperator(const string& str, char pre_char);
  list<string> ToTokens(string str);
  static bool StartsWithNumber(const string &str);
  static bool StartsWithOperator(const string &str);
  static bool StartsWithVariable(const string &str);
  map<string, double> variables;
};

#endif //EX3_EXPRESSIONS_INTERPRETER_H_
