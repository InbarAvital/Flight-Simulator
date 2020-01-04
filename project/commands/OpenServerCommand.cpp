//
// Created by noam on 27/12/2019.
//

#include <iostream>
#include "OpenServerCommand.h"

OpenServerCommand *OpenServerCommand::instance = nullptr;

OpenServerCommand *OpenServerCommand::GetInstance() {
  if (OpenServerCommand::instance == nullptr) {
    OpenServerCommand::instance = new OpenServerCommand();
  }
  return OpenServerCommand::instance;
}

int OpenServerCommand::Execute(vector<string> &tokens, int index) {
  // TODO: Implement function.
  cerr << "OpenServerCommand::Execute(vector<string> &tokens, int index) has no implementation" << endl;
  exit(1);
}

OpenServerCommand::~OpenServerCommand() {
  OpenServerCommand::instance = nullptr;
}
