//
// Created by noam on 27/12/2019.
//

#include <iostream>
#include <thread>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstring>
#include <unistd.h>
#include "ConnectCommand.h"

int ConnectCommand::Execute(vector<string> &tokens, int index) {
  // Gets the arguments.
  string server_address = tokens[index + 1];
  // Removes the " signs.
  server_address = server_address.substr(1, server_address.size() - 2);
  int port = (int) this->shared_data->GetInterpreter()->interpret(tokens[index + 2])->calculate();

  //create socket
  int client_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (client_socket == -1) {
    //error
    std::cerr << "Could not create a socket"<<std::endl;
    exit(1);
  }

  //We need to create a sockaddr obj to hold address of server
  sockaddr_in address; //in means IP4
  address.sin_family = AF_INET;//IP4
  address.sin_addr.s_addr = inet_addr(server_address.c_str());
  address.sin_port = htons(port);
  //we need to convert our number (both port & localhost)
  // to a number that the network understands.

  // Requesting a connection with the server on local host with port 8081
  int is_connect = connect(client_socket, (struct sockaddr *)&address, sizeof(address));
  if (is_connect == -1) {
    std::cerr << "Could not connect to host server"<<std::endl;
    exit(1);
  } else {
    std::cout<<"Client is now connected to server" <<std::endl;
  }

  // Closes the socket when finish.
  this->shared_data->AddSocket(client_socket);

  // Runs the client on different thread.
  thread client_thread(ConnectCommand::RunClient, this, client_socket);
  client_thread.detach();

  return 3;
}

void ConnectCommand::RunClient(ConnectCommand *connect_command, int client_socket) {
  // Gets the messages we need to send.
  queue<string> *outgoing_messages_queue = connect_command->shared_data->GetClientOutgoingMessages();

  while (true) {
    // Sends all messages.
    while (!outgoing_messages_queue->empty()) {
      // Gets the message.
      const char *message = outgoing_messages_queue->front().c_str();

      // Sends the message.
      int is_sent = send(client_socket , message , strlen(message) , 0 );
      if (is_sent == -1) {
        std::cerr<<"Error sending message"<<std::endl;
      }

      outgoing_messages_queue->pop();
    }
  }
}
