//
// Created by noam on 27/12/2019.
//

#include <iostream>
#include "DefineVarCommand.h"

DefineVarCommand *DefineVarCommand::instance = nullptr;

DefineVarCommand *DefineVarCommand::GetInstance() {
  if (DefineVarCommand::instance == nullptr) {
    DefineVarCommand::instance = new DefineVarCommand();
  }
  return DefineVarCommand::instance;
}

int DefineVarCommand::Execute(vector<string> &tokens, int index) {
  // TODO: Implement function.
  cerr << "DefineVarCommand::Execute(vector<string> &tokens, int index) has no implementation" << endl;
  exit(1);
}
