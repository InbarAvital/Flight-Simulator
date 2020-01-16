//
// Created by noam on 15/01/2020.
//

#ifndef EX3_VARIABLES_SHAREDDATA_H_
#define EX3_VARIABLES_SHAREDDATA_H_

#include <queue>

#include "SymbolTable.h"
#include "../expressions/Interpreter.h"

// Holds the data that transfers around the different threads.
class SharedData {
 public:
  // Constructs a Shared Data object.
  SharedData(): symbol_table(new SymbolTable()), interpreter(new Interpreter()), client_outgoing_messages(new queue<string>()) {}

  // Deletes this Shared Data object.
  ~SharedData();

  // Output: The interpreter of this Shared Data object.
  Interpreter *GetInterpreter() {
    return this->interpreter;
  }

  // Output: The client outgoing messages queue of this Shared Data object.
  queue<string> *GetClientOutgoingMessages() {
    return this->client_outgoing_messages;
  }

  // Input: name - The variable's name.
  //        value - The variables's value, if any.
  //        sim - The sim of the variable, if any.
  //        binding_direction - The binding direction, can be "->", "<-", or "=" if there is no sim.
  // Adds new variable to the program.
  void AddVariable(const string& name, float value, const string& sim, const string& binding_direction);

  // Input: name - The variable's name.
  //        value - The variables's new value.
  // Updates the value of the variable to the new value.
  void UpdateVariable(const string& name, float value);

  // Input: variable - the variable's name.
  // Output: The VariableInfo of the variable if this variable has right binding or nullptr otherwise.
  VariableInfo *VarRightBinding(const string& variable);

  // Input: sim - the sim's name.
  // Output: True or false whether if the this sim has left binding to some variable or not.
  string SimLeftBinding(const string& sim);

  // Input: name - A variable name.
  // Output: True or false whether if this variable exists or not..
  bool VariableExists(const string& name);

  void AddSocket(int sock);

 private:
  SymbolTable *symbol_table;
  vector<pair<string, string>> left_binding_variables;
  vector<pair<string, string>> right_binding_variables;
  queue<string> *client_outgoing_messages;
  Interpreter *interpreter;
  list<int> sockets;
};

#endif //EX3_VARIABLES_SHAREDDATA_H_
