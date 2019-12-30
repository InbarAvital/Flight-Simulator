//
// Created by noam on 27/12/2019.
//

#include <iostream>
#include "PrintCommand.h"

PrintCommand *PrintCommand::instance = nullptr;

PrintCommand *PrintCommand::GetInstance() {
  if (PrintCommand::instance == nullptr) {
    PrintCommand::instance = new PrintCommand();
  }
  return PrintCommand::instance;
}

int PrintCommand::Execute(vector<string> &tokens, int index) {
  // TODO: Support expressions.
  // TODO: Support variables.
  string message = tokens[index + 1];
  cout << message << endl;
  return 2;
}
