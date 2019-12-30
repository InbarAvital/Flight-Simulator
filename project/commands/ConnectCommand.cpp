//
// Created by noam on 27/12/2019.
//

#include <iostream>
#include <thread>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "ConnectCommand.h"

int ConnectCommand::Execute() {
  if (this->is_connected) {
    cerr << "Client is already connected to server" << endl;
    exit(1);
  }

  thread connect_thread(ConnectCommand::ConnectClient, this);
  connect_thread.join();
  return 3;
}

void ConnectCommand::ConnectClient(ConnectCommand *connect_command) {
  connect_command->client_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (connect_command->client_socket == -1) {
    cerr << "Failed to create a socket" << endl;
    exit(1);
  }

  sockaddr_in socket_address{};
  socket_address.sin_family = AF_INET;
  socket_address.sin_addr.s_addr = inet_addr(connect_command->address.c_str());
  socket_address.sin_port = htons(connect_command->port);

  connect_command->is_connected = connect(connect_command->client_socket, (struct sockaddr *) &socket_address, sizeof(socket_address)) != -1;
  if (!connect_command->is_connected) {
    cerr << "Failed to connect to server" << endl;
    exit(1);
  }
}

int ConnectCommand::GetClientSocket() {
  return this->client_socket;
}
