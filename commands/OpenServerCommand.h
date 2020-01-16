//
// Created by inbar on 27/12/2019.
//

#ifndef EX3__OPENSERVERCOMMAND_H_
#define EX3__OPENSERVERCOMMAND_H_

#include "Command.h"

// Open Data Server Command is used to open a server to connect the simulator.
class OpenServerCommand : public Command {
 public:
  // Input: data - The shared data.
  // Constructs an Open Server Command.
  explicit OpenServerCommand(SharedData *data): shared_data(data) {}

  int Execute(vector<string> &tokens, int index) override;

 private:
  // Runs the server.
  static void RunServer(OpenServerCommand *open_server_command, int client_socket);

  // Splits strings.
  static vector<string> Split(string str, string split_by);

  SharedData *shared_data;
  map<float, string> index;
};

#endif //EX3__OPENSERVERCOMMAND_H_
