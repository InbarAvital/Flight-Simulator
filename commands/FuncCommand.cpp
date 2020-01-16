//
// Created by noam on 03/01/2020.
//

#include "FuncCommand.h"
#include "AssignToVarCommand.h"

int FuncCommand::Execute(vector<string> &tokens, int index) {
  if (this->has_parameter) {
    // Set the parameter.
    float value = this->shared_data->GetInterpreter()->interpret(tokens[index + 1])->calculate();
    this->shared_data->AddVariable(this->parameter, value, "", "=");
  }
  // Go to the '{' token, which is the start of this function definition's scope.
  int i = this->start_index;
  while (tokens[i] != "{") {
    i++;
  }
  // Continue to the first command inside the scope.
  i++;

  // Execute the commands inside the scope.
  while (tokens[i] != "}") {
    i += this->GetCommand(tokens[i])->Execute(tokens, i);
  }

  if (this->has_parameter) {
    return 2;
  } else {
    return 1;
  }
}

Command *FuncCommand::GetCommand(const string& name) {
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

FuncCommand::FuncCommand(Parser *p, int start): commands(p->GetCommands()), shared_data(p->GetSharedData()), start_index(start) {
  vector<string> tokens = p->GetTokens();
  // Check if has function parameter.
  if (tokens[start + 1] == "var") {
    this->has_parameter = true;
    this->parameter = tokens[start + 2];
  } else {
    this->has_parameter = false;
  }
}
