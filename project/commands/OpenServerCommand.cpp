//
// Created by inbar on 27/12/2019.
//

#include <iostream>
#include <map>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include "OpenServerCommand.h"

int OpenServerCommand::Execute(vector<string> &tokens, int index) {
	// map settings
	value["/instrumentation/airspeed-indicator/indicated-speed-kt"] = 0;
	index[1] = "/instrumentation/airspeed-indicator/indicated-speed-kt";
	value["/sim/time/warp"] = 0;
	index[2] = "/sim/time/warp";
	value["/controls/switches/magnetos"] = 0;
	index[3] = "/controls/switches/magnetos";
	value["/instrumentation/heading-indicator/offset-deg"] = 0;
	index[4] = "/instrumentation/heading-indicator/offset-deg";
	value["/instrumentation/altimeter/indicated-altitude-ft"] = 0;
	index[5] = "/instrumentation/altimeter/indicated-altitude-ft";
	value["/instrumentation/altimeter/pressure-alt-ft"] = 0;
	index[6] = "/instrumentation/altimeter/pressure-alt-ft";
	value["/instrumentation/attitude-indicator/indicated-pitch-deg"] = 0;
	index[7] = "/instrumentation/attitude-indicator/indicated-pitch-deg";
	value["/instrumentation/attitude-indicator/indicated-roll-deg"] = 0;
	index[8] = "/instrumentation/attitude-indicator/indicated-roll-deg";
	value["/instrumentation/attitude-indicator/internal-pitch-deg"] = 0;
	index[9] = "/instrumentation/attitude-indicator/internal-pitch-deg";
	value["/instrumentation/attitude-indicator/internal-roll-deg"] = 0;
	index[10] = "/instrumentation/attitude-indicator/internal-roll-deg";
	value["/instrumentation/encoder/indicated-altitude-ft"] = 0;
	index[11] = "/instrumentation/encoder/indicated-altitude-ft";
	value["/instrumentation/encoder/pressure-alt-ft"] = 0;
	index[12] = "/instrumentation/encoder/pressure-alt-ft";
	value["/instrumentation/gps/indicated-altitude-ft"] = 0;
	index[13] = "/instrumentation/gps/indicated-altitude-ft";
	value["/instrumentation/gps/indicated-ground-speed-kt"] = 0;
	index[14] = "/instrumentation/gps/indicated-ground-speed-kt";
	value["/instrumentation/gps/indicated-vertical-speed"] = 0;
	index[15] = "/instrumentation/gps/indicated-vertical-speed";
	value["/instrumentation/heading-indicator/indicated-heading-deg"] = 0;
	index[16] = "/instrumentation/heading-indicator/indicated-heading-deg";
	value["/instrumentation/magnetic-compass/indicated-heading-deg"] = 0;
	index[17] = "/instrumentation/magnetic-compass/indicated-heading-deg";
	value["/instrumentation/slip-skid-ball/indicated-slip-skid"] = 0;
	index[18] = "/instrumentation/slip-skid-ball/indicated-slip-skid";
	value["/instrumentation/turn-indicator/indicated-turn-rate"] = 0;
	index[19] = "/instrumentation/turn-indicator/indicated-turn-rate";
	value["/instrumentation/vertical-speed-indicator/indicated-speed-fpm"] = 0;
	index[20] = "/instrumentation/vertical-speed-indicator/indicated-speed-fpm";
	value["/controls/flight/aileron"] = 0;
	index[21] = "/controls/flight/aileron";
	value["/controls/flight/elevator"] = 0;
	index[22] = "/controls/flight/elevator";
	value["/controls/flight/rudder"] = 0;
	index[23] = "/controls/flight/rudder";
	value["/controls/flight/flaps"] = 0;
	index[24] = "/controls/flight/flaps";
	value["/controls/engines/engine/throttle"] = 0;
	index[25] = "/controls/engines/engine/throttle";
	value["/controls/engines/current-engine/throttle"] = 0;
	index[26] = "/controls/engines/current-engine/throttle";
	value["/controls/switches/master-avionics"] = 0;
	index[27] = "/controls/switches/master-avionics";
	value["/controls/switches/starter"] = 0;
	index[28] = "/controls/switches/starter";
	value["/engines/active-engine/auto-start"] = 0;
	index[29] = "/engines/active-engine/auto-start";
	value["/controls/flight/speedbrake"] = 0;
	index[30] = "/controls/flight/speedbrake";
	value["/sim/model/c172p/brake-parking"] = 0;
	index[31] = "/sim/model/c172p/brake-parking";
	value["/controls/engines/engine/primer"] = 0;
	index[32] = "/controls/engines/engine/primer";
	value["/controls/engines/current-engine/mixture"] = 0;
	index[33] = "/controls/engines/current-engine/mixture";
	value["/controls/switches/master-bat"] = 0;
	index[34] = "/controls/switches/master-bat";
	value["/controls/switches/master-alt"] = 0;
	index[35] = "/controls/switches/master-alt";
	value["/engines/engine/rpm"] = 0;
	index[36] = "/engines/engine/rpm";

	//create socket
	int socketfd = socket(AF_INET, SOCK_STREAM, 0);
	if (socketfd == -1) {
		//error
		std::cerr << "Could not create a socket" << std::endl;
		return -1;
	}

	//bind socket to IP address
	// we first need to create the sockaddr obj.
	sockaddr_in address; //in means IP4
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY; //give me any IP allocated for my machine
	address.sin_port = htons(token[index + 1]);
	//we need to convert our number
	// to a number that the network understands.

	//the actual bind command
	if (bind(socketfd, (struct sockaddr*) & address, sizeof(address)) == -1) {
		std::cerr << "Could not bind the socket to an IP" << std::endl;
		return -2;
	}

	//making socket listen to the port
	if (listen(socketfd, 5) == -1) { //can also set to SOMAXCON (max connections)
		std::cerr << "Error during listening command" << std::endl;
		return -3;
	}
	else {
		std::cout << "Server is now listening ..." << std::endl;
	}

	// accepting a client
	int client_socket = accept(socketfd, (struct sockaddr*) & address,
		(socklen_t*)&address);

	if (client_socket == -1) {
		std::cerr << "Error accepting client" << std::endl;
		return -4;
	}
	// thread creation
	std::thread server_thread(Server, tokens, index);
	server_thread.detach();

	return 2;
}

void Server(vector<string>& tokens, int index) {
	//reading from client
	char buffer[1024] = { 0 };
	int valread = read(client_socket, buffer, 1024);
	int i;
	vector<string> values = Split(valread, ",");
	for (i = 0; i < 36; i++) {
		value[index[i + 1]] = atof(values[i]);
	}
	close(socketfd); //closing the listening socket
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
vector<string> Lexer::Split(string str, string split_by) {
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
