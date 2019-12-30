//
// Created by noam on 27/12/2019.
//

#ifndef EX3__OPENSERVERCOMMAND_H_
#define EX3__OPENSERVERCOMMAND_H_

#include "Command.h"

class OpenServerCommand : public Command {
 public:
  explicit OpenServerCommand(int p): port(p) {}
  int Execute() override;

 private:
  int port;
};

#endif //EX3__OPENSERVERCOMMAND_H_
