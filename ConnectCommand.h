//
// Created by noam on 27/12/2019.
//

#ifndef EX3__CONNECTCOMMAND_H_
#define EX3__CONNECTCOMMAND_H_

#include <utility>
#include "Command.h"

class ConnectCommand : public Command {
 public:
  ConnectCommand(string a, int p): address(move(a)), port(p) {}
  int Execute() override;
  static void ConnectClient(ConnectCommand *connect_command);
  int GetClientSocket();

 private:
  string address;
  int port;
  int client_socket;
  bool is_connected = false;
};

#endif //EX3__CONNECTCOMMAND_H_
