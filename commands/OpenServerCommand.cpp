//
// Created by inbar on 27/12/2019.
//

#include <iostream>
#include <map>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <thread>
#include "OpenServerCommand.h"

int OpenServerCommand::Execute(vector<string> &tokens, int token_index) {
	// map settings
	index[1] = "/instrumentation/airspeed-indicator/indicated-speed-kt";
	index[2] = "/sim/time/warp";
	index[3] = "/controls/switches/magnetos";
	index[4] = "/instrumentation/heading-indicator/offset-deg";
	index[5] = "/instrumentation/altimeter/indicated-altitude-ft";
	index[6] = "/instrumentation/altimeter/pressure-alt-ft";
	index[7] = "/instrumentation/attitude-indicator/indicated-pitch-deg";
	index[8] = "/instrumentation/attitude-indicator/indicated-roll-deg";
	index[9] = "/instrumentation/attitude-indicator/internal-pitch-deg";
	index[10] = "/instrumentation/attitude-indicator/internal-roll-deg";
	index[11] = "/instrumentation/encoder/indicated-altitude-ft";
	index[12] = "/instrumentation/encoder/pressure-alt-ft";
	index[13] = "/instrumentation/gps/indicated-altitude-ft";
	index[14] = "/instrumentation/gps/indicated-ground-speed-kt";
	index[15] = "/instrumentation/gps/indicated-vertical-speed";
	index[16] = "/instrumentation/heading-indicator/indicated-heading-deg";
	index[17] = "/instrumentation/magnetic-compass/indicated-heading-deg";
	index[18] = "/instrumentation/slip-skid-ball/indicated-slip-skid";
	index[19] = "/instrumentation/turn-indicator/indicated-turn-rate";
	index[20] = "/instrumentation/vertical-speed-indicator/indicated-speed-fpm";
	index[21] = "/controls/flight/aileron";
	index[22] = "/controls/flight/elevator";
	index[23] = "/controls/flight/rudder";
	index[24] = "/controls/flight/flaps";
	index[25] = "/controls/engines/engine/throttle";
	index[26] = "/controls/engines/current-engine/throttle";
	index[27] = "/controls/switches/master-avionics";
	index[28] = "/controls/switches/starter";
	index[29] = "/engines/active-engine/auto-start";
	index[30] = "/controls/flight/speedbrake";
	index[31] = "/sim/model/c172p/brake-parking";
	index[32] = "/controls/engines/engine/primer";
	index[33] = "/controls/engines/current-engine/mixture";
	index[34] = "/controls/switches/master-bat";
	index[35] = "/controls/switches/master-alt";
	index[36] = "/engines/engine/rpm";

	//create socket
	int socketfd = socket(AF_INET, SOCK_STREAM, 0);
	if (socketfd == -1) {
		//error
		std::cerr << "Could not create a socket" << std::endl;
        exit(1);
	}

	//bind socket to IP address
	// we first need to create the sockaddr obj.
	sockaddr_in address; //in means IP4
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY; //give me any IP allocated for my machine
	address.sin_port = htons(stoi(tokens[token_index + 1]));
	//we need to convert our number
	// to a number that the network understands.

	//the actual bind command
	if (bind(socketfd, (struct sockaddr*) & address, sizeof(address)) == -1) {
		std::cerr << "Could not bind the socket to an IP" << std::endl;
		exit(1);
	}

	//making socket listen to the port
	if (listen(socketfd, 5) == -1) { //can also set to SOMAXCON (max connections)
		std::cerr << "Error during listening command" << std::endl;
        exit(1);
	}
	else {
		std::cout << "Server is now listening ..." << std::endl;
	}

	// accepting a client
	int client_socket = accept(socketfd, (struct sockaddr*) & address,
		(socklen_t*)&address);

	if (client_socket == -1) {
		std::cerr << "Error accepting client" << std::endl;
        exit(1);
	}

	// Closes the socket when finish.
	this->shared_data->AddSocket(client_socket);

    close(socketfd); //closing the listening socket

	// thread creation
	std::thread server_thread(OpenServerCommand::RunServer, this, client_socket);
	server_thread.detach();

	return 2;
}

void OpenServerCommand::RunServer(OpenServerCommand *open_server_command, int client_socket) {
    // Gets the value and index maps.
    map<float, string> index = open_server_command->index;

    while (true) {
      char buffer[1024] = { 0 };

      //reading from client
      int valread = read(client_socket, buffer, 1024);
      int i;
      vector<string> lines = Split(buffer, "\n");

      for (auto line : lines) {
        vector<string> values = Split(line, ",");
        // Update each value.
        for (i = 0; i < 36; i++) {
          string var_name = open_server_command->shared_data->SimLeftBinding(index[i + 1]);
          open_server_command->shared_data->UpdateVariable(var_name, stof(values[i]));
        }
      }
    }
}

/*
 * Arguments:
 *          # string str = the string we want to split
 *          # string split_by = the string to split "str" by.
 *
 * We split the "str" string every time we see the "split_by" string.
 *
 * Returns a vector of the splitted parts of the string.
 */
vector<string> OpenServerCommand::Split(string str, string split_by) {
	// true every time we find a split_by string
	bool found;
	// a string to add until we find a split_by string
	string to_add = "";
	// the splitted list we send in the end
	vector<string> splitted;
	// for loop on each char in "str"
	for (int i = 0; i < str.length(); i++) {
		found = true;
		// for loop to check if this current char is the beginning of "split_by"
		int i_copy = i;
		for (int j = 0; j < split_by.length(); j++) {
			if (str[i_copy + j] != split_by[j]) {
				found = false;
				i_copy += j;
				break;
			}
		}
		// if we find a "split_by", we add what was before the it and not yes
		// added to the list, ignore the "split_by", and continue
		if (found) {
			i += split_by.length() - 1;
			if (to_add != "")
				splitted.push_back(to_add);
			to_add = "";
		}
		else {
			to_add += str[i];
			if (i == str.length() - 1) {
				splitted.push_back(to_add);
			}
		}
	}
	return splitted;
}
