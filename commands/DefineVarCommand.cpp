//
// Created by noam on 27/12/2019.
//

#include <iostream>
#include "DefineVarCommand.h"

int DefineVarCommand::Execute(vector<string> &tokens, int index) {
  // Gets the arguments.
  string name = tokens[index + 1];
  string binding_direction = tokens[index + 2];

  if (tokens[index + 3] != "sim") {
    // Defines new normal variable.
    float value = this->shared_data->GetInterpreter()->interpret(tokens[index + 3])->calculate();
    this->shared_data->AddVariable(name, value, "", binding_direction);
    return 4;
  } else {
    // Defines new variable with binding.
    string sim = tokens[index + 4];
    sim = sim.substr(1, sim.size() - 2);
    this->shared_data->AddVariable(name, 0, sim, binding_direction);
    return 5;
  }
}
