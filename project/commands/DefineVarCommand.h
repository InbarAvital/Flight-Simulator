//
// Created by noam on 27/12/2019.
//

#ifndef EX3__DEFINEVARCOMMAND_H_
#define EX3__DEFINEVARCOMMAND_H_

#include "Command.h"

class DefineVarCommand : public Command {
 public:
  int Execute() override;
};

#endif //EX3__DEFINEVARCOMMAND_H_
