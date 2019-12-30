//
// Created by noam on 27/12/2019.
//

#include <thread>
#include "SleepCommand.h"

SleepCommand *SleepCommand::instance = nullptr;

SleepCommand *SleepCommand::GetInstance() {
  if (SleepCommand::instance == nullptr) {
    SleepCommand::instance = new SleepCommand();
  }
  return SleepCommand::instance;
}

int SleepCommand::Execute(vector<string> &tokens, int index) {
  // TODO: Support expressions.
  // TODO: Support variables.
  int milliseconds = stoi(tokens[index + 1]);
  this_thread::sleep_for(chrono::milliseconds(milliseconds));
  return 2;
}
