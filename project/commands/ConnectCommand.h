//
// Created by noam on 27/12/2019.
//

#ifndef EX3__CONNECTCOMMAND_H_
#define EX3__CONNECTCOMMAND_H_

#include <utility>
#include "Command.h"
#include "../variables/SharedData.h"

// TODO: Fill the comment.
// Connect Control Client Command is used to _____________.
class ConnectCommand : public Command {
 public:
  // Input: data - The shared data.
  // Constructs a Connect Command.
  explicit ConnectCommand(SharedData *data): shared_data(data) {}
  int Execute(vector<string> &tokens, int index) override;

 private:
  SharedData *shared_data;
};

#endif //EX3__CONNECTCOMMAND_H_
