//
// Created by noam on 03/01/2020.
//

#ifndef EX3_COMMANDS_FUNCCOMMAND_H_
#define EX3_COMMANDS_FUNCCOMMAND_H_

#include "Command.h"
#include "../parser/Parser.h"

// A Function is a set of commands defined by the user (code).
class FuncCommand : public Command {
 public:
  // Input: p - The original parser.
  //        start - The index of the first token belongs to the function declaration.
  // Constructs a function with a set of commands starting from the provided index.
  FuncCommand(Parser *p, int start): commands(p->GetCommands()), start_index(start) {}

  virtual ~FuncCommand() = default;

  int Execute(vector<string> &tokens, int index) override;

 private:
  map<string, Command *> *commands;
  int start_index;
};

#endif //EX3_COMMANDS_FUNCCOMMAND_H_
