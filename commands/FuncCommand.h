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
  FuncCommand(Parser *p, int start);

  virtual ~FuncCommand() = default;

  int Execute(vector<string> &tokens, int index) override;

  // Input: name - the key of some command from the commands map.
  // Output: The matching command from the map.
  Command *GetCommand(const string& name);

 private:
  map<string, Command *> *commands;
  SharedData *shared_data;
  int start_index;
  bool has_parameter;
  string parameter;
  vector<Command *> to_delete;
};

#endif //EX3_COMMANDS_FUNCCOMMAND_H_
