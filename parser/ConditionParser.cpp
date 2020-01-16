//
// Created by noam on 03/01/2020.
//

#include <iostream>
#include "ConditionParser.h"
#include "../expressions/Interpreter.h"
#include "../commands/AssignToVarCommand.h"

bool ConditionParser::CheckCondition() {
  double left, right;
  Interpreter *interpreter = this->shared_data->GetInterpreter();

  // Calculates values for the condition's left and right arguments.
  left = interpreter->interpret(this->left_argument)->calculate();
  right = interpreter->interpret(this->right_argument)->calculate();

  // Checks if the condition is satisfies according to the condition's operator.
  if (this->condition_operator == "<") {
    return left < right;
  } else if (this->condition_operator == ">") {
    return left > right;
  } else if (this->condition_operator == "<=") {
    return left <= right;
  } else if (this->condition_operator == ">=") {
    return left >= right;
  } else if (this->condition_operator == "==") {
    return left == right;
  } else if (this->condition_operator == "!=") {
    return left != right;
  } else {
    return false;
  }
}

void ConditionParser::InitCondition(vector<string> tokens, int index) {
  this->left_argument = tokens[index + 1];
  this->condition_operator = tokens[index + 2];
  this->right_argument = tokens[index + 3];
}

Command *ConditionParser::GetCommand(const string& name) {
  Command *command = nullptr;

  if (this->commands->count(name) > 0) {
    command = this->commands->at(name);
  } else if (this->shared_data->VariableExists(name)) {
    // Assign value to existing variable.
    command = new AssignToVarCommand(this->shared_data);
    // Not inside map so we need to delete this when deleting this object.
    this->to_delete.push_back(command);
  }
  return command;
}

ConditionParser::~ConditionParser() {
  // Deletes commands that are not inside the map.
  for (auto command : this->to_delete) {
    delete command;
  }
}
