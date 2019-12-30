//
// Created by noam on 27/12/2019.
//

#include <iostream>
#include "PrintCommand.h"

int PrintCommand::Execute() {
  cout << this->message << endl;
  return 2;
}
