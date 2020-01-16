//
// Created by noam on 27/12/2019.
//

#include <thread>
#include <iostream>
#include "SleepCommand.h"
#include "../expressions/Interpreter.h"

int SleepCommand::Execute(vector<string> &tokens, int index) {
  // Get argument.
  int milliseconds = (int) this->shared_data->GetInterpreter()->interpret(tokens[index + 1])->calculate();

  // Sleeps for this amount of time.
  this_thread::sleep_for(chrono::milliseconds(milliseconds));

  return 2;
}
