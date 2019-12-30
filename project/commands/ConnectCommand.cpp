//
// Created by noam on 27/12/2019.
//

#include <iostream>
#include <thread>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "ConnectCommand.h"

ConnectCommand *ConnectCommand::instance = nullptr;

ConnectCommand *ConnectCommand::GetInstance() {
  if (ConnectCommand::instance == nullptr) {
    ConnectCommand::instance = new ConnectCommand();
  }
  return ConnectCommand::instance;
}

int ConnectCommand::Execute(vector<string> &tokens, int index) {
  // TODO: Implement function.
  cerr << "ConnectCommand::Execute(vector<string> &tokens, int index) has no implementation" << endl;
  exit(1);
}
