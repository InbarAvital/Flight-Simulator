//
// Created by noam on 03/01/2020.
//

#include "IfCommand.h"

int IfCommand::Execute(vector<string> &tokens, int index) {
  // Initializes the condition of this If Command.
  this->InitCondition(tokens, index);

  // Go to the '{' token, which is the start of this If Command's scope.
  int i = index;
  while (tokens[i] != "{") {
    i++;
  }
  // Continue to the first command inside the scope.
  i++;

  // Checks whether the condition is satisfied or not.
  if (this->CheckCondition()) {
    // The condition is satisfied, then execute the commands inside the scope.
    while (tokens[i] != "}") {
      i += this->GetCommand(tokens[i])->Execute(tokens, i);
    }
  } else {
    // The condition is not satisfied, then skip to the end.
    while (tokens[i] != "}") {
      i++;
    }
  }
  return i - index + 1;
}
