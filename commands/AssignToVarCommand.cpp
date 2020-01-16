//
// Created by noam on 16/01/2020.
//

#include "AssignToVarCommand.h"

int AssignToVarCommand::Execute(vector<string> &tokens, int index) {
  // Gets the name.
  string name = tokens[index];

  // Gets the value.
  float value = (float) this->shared_data->GetInterpreter()->interpret(tokens[index + 2])->calculate();

  // Updates the variable's value.
  this->shared_data->UpdateVariable(name, value);

  return 3;
}
