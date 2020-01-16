//
// Created by noam on 16/01/2020.
//

#ifndef EX3_COMMANDS_ASSIGNTOVARCOMMAND_H_
#define EX3_COMMANDS_ASSIGNTOVARCOMMAND_H_

#include "Command.h"

// Assign to Var Command is used to assign new value to an existing variable inside the program.
class AssignToVarCommand : public Command {
 public:
  // Input: data - The shared data.
  // Constructs a Define Var Command.
  explicit AssignToVarCommand(SharedData *data): shared_data(data) {}
  int Execute(vector<string> &tokens, int index) override;

 private:
  SharedData *shared_data;
};

#endif //EX3_COMMANDS_ASSIGNTOVARCOMMAND_H_
