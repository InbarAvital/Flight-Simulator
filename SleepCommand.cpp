//
// Created by noam on 27/12/2019.
//

#include <thread>
#include "SleepCommand.h"

int SleepCommand::Execute() {
  this_thread::sleep_for(chrono::milliseconds(this->milliseconds));
  return 2;
}
