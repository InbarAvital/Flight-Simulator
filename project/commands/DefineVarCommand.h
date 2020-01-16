//
// Created by noam on 27/12/2019.
//

#ifndef EX3__DEFINEVARCOMMAND_H_
#define EX3__DEFINEVARCOMMAND_H_

#include "Command.h"
#include "../variables/SharedData.h"

// Define Var Command is used to define and initialize a new variable inside the program.
class DefineVarCommand : public Command {
 public:
  // Input: data - The shared data.
  // Constructs a Define Var Command.
  explicit DefineVarCommand(SharedData *data): shared_data(data) {}
  int Execute(vector<string> &tokens, int index) override;

 private:
  SharedData *shared_data;
};

#endif //EX3__DEFINEVARCOMMAND_H_
