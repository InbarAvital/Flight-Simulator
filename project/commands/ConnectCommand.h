//
// Created by noam on 27/12/2019.
//

#ifndef EX3__CONNECTCOMMAND_H_
#define EX3__CONNECTCOMMAND_H_

#include <utility>
#include "Command.h"

// TODO: Fill the comment.
// Connect Control Client Command is used to _____________.
// This class uses the singleton design pattern and has only one instance.
class ConnectCommand : public Command {
 public:
  // Deletes the single instance of this class.
  virtual ~ConnectCommand();

  int Execute(vector<string> &tokens, int index) override;

  // Output: The single instance of this class.
  static ConnectCommand *GetInstance();

 private:
  ConnectCommand() = default;
  static ConnectCommand *instance;
};

#endif //EX3__CONNECTCOMMAND_H_
