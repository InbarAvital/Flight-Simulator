//
// Created by noam on 27/12/2019.
//

#ifndef EX3__SLEEPCOMMAND_H_
#define EX3__SLEEPCOMMAND_H_

#include "Command.h"
#include "../variables/SharedData.h"

// Sleep Command is used to pause the program for a couple of milliseconds.
class SleepCommand : public Command {
 public:
  // Input: data - The shared data.
  // Constructs a Sleep Command.
  explicit SleepCommand(SharedData *data): shared_data(data) {}
  int Execute(vector<string> &tokens, int index) override;

 private:
  SharedData *shared_data;
};

#endif //EX3__SLEEPCOMMAND_H_
