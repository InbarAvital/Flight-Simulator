//
// Created by noam on 27/12/2019.
//

#ifndef EX3_COMMAND_H
#define EX3_COMMAND_H

#include <string>
#include <vector>

using namespace std;

// Command is a lexical token which can be executed and cause the program to
// preform an action.
// This is an abstract class, and each type of command has its own class which
// derives from this abstract class.
// Every derived class should use the singleton design pattern.
class Command {
 public:
  // Input: data - The lexical tokens.
  //        index - The index of the executing command from the lexical tokens.
  // Output: The number of lexical tokens until the next command.
  // Executes a command from the lexical tokens.
  virtual int Execute(vector<string> &tokens, int index) = 0;

  virtual ~Command() = default;
};

#endif //EX3_COMMAND_H
