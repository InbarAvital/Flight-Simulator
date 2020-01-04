//
// Created by noam on 27/12/2019.
//

#include <iostream>
#include "PrintCommand.h"
#include "../expressions/Interpreter.h"

PrintCommand *PrintCommand::instance = nullptr;

PrintCommand *PrintCommand::GetInstance() {
  if (PrintCommand::instance == nullptr) {
    PrintCommand::instance = new PrintCommand();
  }
  return PrintCommand::instance;
}

int PrintCommand::Execute(vector<string> &tokens, int index) {
  // TODO: Support variables.
  string message = tokens[index + 1];
  if (message[0] == '\"' && message[message.size() - 1] == '\"') {
    cout << message.substr(1, message.size() - 2) << endl;
  } else {
    Interpreter *interpreter = new Interpreter();
    try {
      cout << interpreter->interpret(message)->calculate() << endl;
    } catch (const char* e) {
      cout << e << endl;
    }
  }
  return 2;
}

PrintCommand::~PrintCommand() {
  PrintCommand::instance = nullptr;
}
