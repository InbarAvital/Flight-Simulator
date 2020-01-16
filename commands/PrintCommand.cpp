//
// Created by noam on 27/12/2019.
//

#include <iostream>
#include "PrintCommand.h"
#include "../expressions/Interpreter.h"

int PrintCommand::Execute(vector<string> &tokens, int index) {
  // Gets the argument.
  string message = tokens[index + 1];

  // Prints it to the user.
  if (message[0] == '\"' && message[message.size() - 1] == '\"') {
    cout << message.substr(1, message.size() - 2) << endl;
  } else {
    cout << this->shared_data->GetInterpreter()->interpret(message)->calculate() << endl;
  }

  return 2;
}
