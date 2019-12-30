//
// Created by noam on 27/12/2019.
//

#ifndef EX3__OPENSERVERCOMMAND_H_
#define EX3__OPENSERVERCOMMAND_H_

#include "Command.h"

// TODO: Fill the comment.
// Open Data Server Command is used to _____________.
// This class uses the singleton design pattern and has only one instance.
class OpenServerCommand : public Command {
 public:
  int Execute(vector<string> &tokens, int index) override;

  // Output: The single instance of this class.
  static OpenServerCommand *GetInstance();

 private:
  OpenServerCommand() = default;
  static OpenServerCommand *instance;
};

#endif //EX3__OPENSERVERCOMMAND_H_
