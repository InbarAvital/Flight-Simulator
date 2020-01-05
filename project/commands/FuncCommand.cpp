//
// Created by noam on 03/01/2020.
//

#include "FuncCommand.h"

int FuncCommand::Execute(vector<string> &tokens, int index) {
  // TODO: Accept up to one variable as function parameter.
  // Go to the '{' token, which is the start of this function definition's scope.
  int i = index;
  while (tokens[i] != "{") {
    i++;
  }
  // Continue to the first command inside the scope.
  i++;

  // Execute the commands inside the scope.
  while (tokens[i] != "}") {
    i += this->commands->at(tokens[i])->Execute(tokens, i);
  }

  return i - index + 1;
}
