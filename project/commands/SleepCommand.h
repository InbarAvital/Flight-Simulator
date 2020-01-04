//
// Created by noam on 27/12/2019.
//

#ifndef EX3__SLEEPCOMMAND_H_
#define EX3__SLEEPCOMMAND_H_

#include "Command.h"

// Sleep Command is used to pause the program for a couple of milliseconds.
// This class uses the singleton design pattern and has only one instance.
class SleepCommand : public Command {
 public:
  // Deletes the single instance of this class.
  virtual ~SleepCommand();

  int Execute(vector<string> &tokens, int index) override;

  // Output: The single instance of this class.
  static SleepCommand *GetInstance();

 private:
  SleepCommand() = default;
  static SleepCommand *instance;
};

#endif //EX3__SLEEPCOMMAND_H_
