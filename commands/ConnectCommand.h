//
// Created by noam on 27/12/2019.
//

#ifndef EX3__CONNECTCOMMAND_H_
#define EX3__CONNECTCOMMAND_H_

#include <utility>
#include "Command.h"
#include "../variables/SharedData.h"

// Connect Control Client Command is used to connect a client that will control flight.
class ConnectCommand : public Command {
 public:
  // Input: data - The shared data.
  // Constructs a Connect Command.
  explicit ConnectCommand(SharedData *data): shared_data(data) {}

  int Execute(vector<string> &tokens, int index) override;

  static void RunClient(ConnectCommand *connect_command, int client_socket);

 private:
  SharedData *shared_data;
};

#endif //EX3__CONNECTCOMMAND_H_
