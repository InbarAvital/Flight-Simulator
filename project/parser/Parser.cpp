//
// Created by noam on 30/12/2019.
//

#include "Parser.h"

void Parser::AddCommand(const string &name, Command *command) {
  this->commands[name] = command;
}

void Parser::Parse() {
  int index = 0;

  while (index < this->tokens.size()) {
    // Analyzes the current command.
    Command *command = this->commands[this->tokens[index]];

    // Executes the command and move to the next one.
    index += command->Execute(this->tokens, index);
  }
}

Parser::~Parser() {
  for (const auto& command : this->commands) {
    delete command.second;
  }
}
