//
// Created by noam on 30/12/2019.
//

#include "Parser.h"
#include "../commands/FuncCommand.h"

void Parser::AddCommand(const string &name, Command *command) {
  this->commands->insert({name, command});
}

void Parser::Parse() {
  int index = 0;

  while (index < this->tokens.size()) {
    // Analyzes the current command.
    if (this->commands->count(this->tokens[index]) != 0) {
      Command *command = this->commands->at(this->tokens[index]);

      // Executes the command and move to the next one.
      index += command->Execute(this->tokens, index);
    } else {
      // Defines new function.
      this->AddCommand(this->tokens[index], new FuncCommand(this, index));

      // Continues to the next command.
      while (tokens[index] != "}") {
        index++;
      }
      index++;
    }
  }
}

Parser::~Parser() {
  delete this->commands;
}
