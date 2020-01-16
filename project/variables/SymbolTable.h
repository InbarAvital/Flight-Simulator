//
// Created by noam on 15/01/2020.
//

#ifndef EX3_VARIABLES_SYMBOLTABLE_H_
#define EX3_VARIABLES_SYMBOLTABLE_H_

#include <map>
#include <vector>
#include "VariableInfo.h"

class SymbolTable {
 public:
  // Input: variable - A variable name.
  // Output: The information of this variable from this table, or null if not inside table.
  VariableInfo *get(const string& variable);

  // Input: name - A variable name.
  //        variable_info - This variable information.
  // Adds this variable to this table.
  void Add(const string& name, VariableInfo *variable_info);

  // Input: name - A variable name.
  // Output: True or false whether if this variable exists or not..
  bool Exists(const string& name);

 private:
  map<string, VariableInfo *> table;
};

#endif //EX3_VARIABLES_SYMBOLTABLE_H_
