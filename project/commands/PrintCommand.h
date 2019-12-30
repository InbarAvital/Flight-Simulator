//
// Created by noam on 27/12/2019.
//

#ifndef EX3__PRINTCOMMAND_H_
#define EX3__PRINTCOMMAND_H_

#include <utility>
#include "Command.h"

// Print Command is used to print the provided message to the user.
// This class uses the singleton design pattern and has only one instance.
class PrintCommand : public Command {
 public:
  int Execute(vector<string> &tokens, int index) override;

  // Output: The single instance of this class.
  static PrintCommand *GetInstance();

 private:
  PrintCommand() = default;
  static PrintCommand *instance;
};

#endif //EX3__PRINTCOMMAND_H_
