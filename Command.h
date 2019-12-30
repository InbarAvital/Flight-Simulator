//
// Created by noam on 27/12/2019.
//

#ifndef EX3_COMMAND_H
#define EX3_COMMAND_H

#include <string>

using namespace std;

class Command {
 public:
  virtual int Execute() = 0;
  virtual ~Command() = default;
};

#endif //EX3_COMMAND_H
