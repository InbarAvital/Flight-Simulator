//
// Created by noam on 27/12/2019.
//

#ifndef EX3__PRINTCOMMAND_H_
#define EX3__PRINTCOMMAND_H_

#include <utility>
#include "Command.h"
#include "../variables/SharedData.h"

// Print Command is used to print the provided message to the user.
class PrintCommand : public Command {
 public:
  // Input: data - The shared data.
  // Constructs a Print Command.
  explicit PrintCommand(SharedData *data): shared_data(data) {}
  int Execute(vector<string> &tokens, int index) override;

 private:
  SharedData *shared_data;
};

#endif //EX3__PRINTCOMMAND_H_
