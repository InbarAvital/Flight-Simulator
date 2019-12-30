//
// Created by noam on 27/12/2019.
//

#ifndef EX3__DEFINEVARCOMMAND_H_
#define EX3__DEFINEVARCOMMAND_H_

#include "Command.h"

// TODO: Fill the comment.
// Var Command is used to define and initialize a new variable inside the program.
// This class uses the singleton design pattern and has only one instance.
class DefineVarCommand : public Command {
 public:
  int Execute(vector<string> &tokens, int index) override;

  // Output: The single instance of this class.
  static DefineVarCommand *GetInstance();

 private:
  DefineVarCommand() = default;
  static DefineVarCommand *instance;
};

#endif //EX3__DEFINEVARCOMMAND_H_
