//
// Created by noam on 27/12/2019.
//

#ifndef EX3__SLEEPCOMMAND_H_
#define EX3__SLEEPCOMMAND_H_

#include "Command.h"

class SleepCommand : public Command {
 public:
  explicit SleepCommand(int m): milliseconds(m) {}
  int Execute() override;

 private:
  int milliseconds;
};

#endif //EX3__SLEEPCOMMAND_H_
