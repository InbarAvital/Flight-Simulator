//
// Created by noam on 03/01/2020.
//

#include "LoopCommand.h"

int LoopCommand::Execute(vector<string> &tokens, int index) {
  // Initializes the condition of this Loop Command.
  this->InitCondition(tokens, index);

  // Go to the '{' token, which is the start of this Loop Command's scope.
  int i = index;
  while (tokens[i] != "{") {
    i++;
  }
  // Continue to the first command inside the scope.
  i++;
  int first_command_index = i;

  // Keeps executing the commands as long as the condition is satisfied.
  while (this->CheckCondition()) {
    // The condition is satisfied, then execute the commands inside the scope.
    while (tokens[i] != "}") {
      i += this->GetCommand(tokens[i])->Execute(tokens, i);
    }
    // Jumps back to the first command in the scope.
    i = first_command_index;
  }
  // The condition is not satisfied, then skip to the end.
  while (tokens[i] != "}") {
    i++;
  }
  return i - index + 1;
}
