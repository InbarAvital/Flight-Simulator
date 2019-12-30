//
// Created by noam on 27/12/2019.
//

#ifndef EX3__PRINTCOMMAND_H_
#define EX3__PRINTCOMMAND_H_

#include <utility>
#include "Command.h"

class PrintCommand : public Command {
 public:
  explicit PrintCommand(string s): message(move(s)) {}
  int Execute() override;

 private:
  string message;
};

#endif //EX3__PRINTCOMMAND_H_
