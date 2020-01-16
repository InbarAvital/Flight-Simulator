//
// Created by noam on 15/01/2020.
//

#include "SymbolTable.h"

VariableInfo *SymbolTable::Get(const string& variable) {
  if (this->table.count(variable) == 0) {
    return nullptr;
  } else {
    return table[variable];
  }
}

void SymbolTable::Add(const string& name, VariableInfo *variable_info) {
  table[name] = variable_info;
}

bool SymbolTable::Exists(const string& name) {
  return this->table.count(name) > 0;
}
